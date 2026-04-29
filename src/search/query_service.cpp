#include "search/query_service.hpp"

#include <algorithm>
#include <cctype>
#include <sstream>
#include <string>
#include <unordered_set>

namespace mylib::search {

namespace {

std::string to_lower_copy(const std::string& value) {
    std::string out = value;
    std::transform(out.begin(), out.end(), out.begin(), [](unsigned char c) {
        return static_cast<char>(std::tolower(c));
    });
    return out;
}

std::vector<std::string> tokenize(const std::string& query) {
    std::vector<std::string> out;
    std::string current;
    for (char c : query) {
        if (std::isspace(static_cast<unsigned char>(c))) {
            if (!current.empty()) {
                out.push_back(current);
                current.clear();
            }
            continue;
        }
        if (c == '(' || c == ')') {
            if (!current.empty()) {
                out.push_back(current);
                current.clear();
            }
            out.emplace_back(1, c);
            continue;
        }
        current.push_back(c);
    }
    if (!current.empty()) {
        out.push_back(current);
    }
    return out;
}

bool is_operator(const std::string& token) {
    const auto lowered = to_lower_copy(token);
    return lowered == "and" || lowered == "or" || lowered == "not";
}

int precedence(const std::string& op) {
    const auto lowered = to_lower_copy(op);
    if (lowered == "not") return 3;
    if (lowered == "and") return 2;
    if (lowered == "or") return 1;
    return 0;
}

bool evaluate_rpn(const std::vector<std::string>& rpn, const std::string& haystack, bool* ok) {
    std::vector<bool> stack;
    *ok = true;

    for (const auto& token : rpn) {
        if (!is_operator(token)) {
            stack.push_back(haystack.find(to_lower_copy(token)) != std::string::npos);
            continue;
        }

        const auto op = to_lower_copy(token);
        if (op == "not") {
            if (stack.empty()) {
                *ok = false;
                return false;
            }
            const bool value = stack.back();
            stack.back() = !value;
            continue;
        }

        if (stack.size() < 2) {
            *ok = false;
            return false;
        }
        const bool rhs = stack.back();
        stack.pop_back();
        const bool lhs = stack.back();
        stack.pop_back();
        stack.push_back(op == "and" ? (lhs && rhs) : (lhs || rhs));
    }

    if (stack.size() != 1) {
        *ok = false;
        return false;
    }
    return stack.back();
}

std::vector<std::string> extract_terms(const std::vector<std::string>& tokens) {
    std::vector<std::string> terms;
    std::unordered_set<std::string> seen;
    for (const auto& token : tokens) {
        if (token == "(" || token == ")") continue;
        const auto lowered = to_lower_copy(token);
        if (is_operator(lowered)) continue;
        if (seen.insert(lowered).second) {
            terms.push_back(lowered);
        }
    }
    return terms;
}

struct ScoredRecord {
    mylib::domain::CatalogRecord record;
    int score = 0;
};

int count_matches(const std::string& haystack, const std::vector<std::string>& terms) {
    int hits = 0;
    for (const auto& term : terms) {
        if (haystack.find(term) != std::string::npos) ++hits;
    }
    return hits;
}

int score_record(const mylib::domain::CatalogRecord& record, const std::vector<std::string>& terms) {
    const auto lower_title = to_lower_copy(record.title);
    std::string lower_tags;
    for (const auto& tag : record.tags) {
        if (!lower_tags.empty()) lower_tags.push_back(' ');
        lower_tags.append(to_lower_copy(tag));
    }

    const int title_hits = count_matches(lower_title, terms);
    const int tag_hits = count_matches(lower_tags, terms);
    return (title_hits * 3) + (tag_hits * 2);
}

std::string build_diagnostics(
    const std::vector<std::string>& terms,
    int title_boost,
    int tag_boost,
    std::size_t total_matches
) {
    std::ostringstream oss;
    oss << "ranking=title*" << title_boost
        << "+tags*" << tag_boost
        << "; terms=" << terms.size()
        << "; matches=" << total_matches;
    return oss.str();
}

void stable_rank(std::vector<ScoredRecord>* records) {
    std::stable_sort(records->begin(), records->end(), [](const ScoredRecord& lhs, const ScoredRecord& rhs) {
        if (lhs.score != rhs.score) return lhs.score > rhs.score;
        const auto lhs_title = to_lower_copy(lhs.record.title);
        const auto rhs_title = to_lower_copy(rhs.record.title);
        if (lhs_title != rhs_title) return lhs_title < rhs_title;
        return lhs.record.id < rhs.record.id;
    });
}

std::optional<std::vector<std::string>> to_rpn(const std::vector<std::string>& tokens) {
    std::vector<std::string> output;
    std::vector<std::string> ops;

    const auto pop_until_left_paren = [&](void) -> bool {
        while (!ops.empty()) {
            const auto op = ops.back();
            ops.pop_back();
            if (op == "(") return true;
            output.push_back(op);
        }
        return false;
    };

    const auto push_operator = [&](const std::string& lowered) {
        while (!ops.empty() && is_operator(ops.back()) &&
               precedence(ops.back()) >= precedence(lowered)) {
            output.push_back(ops.back());
            ops.pop_back();
        }
        ops.push_back(lowered);
    };

    const auto push_token = [&](const std::string& token) -> bool {
        if (token == "(") {
            ops.push_back(token);
            return true;
        }
        if (token == ")") {
            return pop_until_left_paren();
        }

        const auto lowered = to_lower_copy(token);
        if (is_operator(lowered)) {
            push_operator(lowered);
            return true;
        }

        output.push_back(token);
        return true;
    };

    for (const auto& token : tokens) {
        if (!push_token(token)) return std::nullopt;
    }

    while (!ops.empty()) {
        if (ops.back() == "(" || ops.back() == ")") return std::nullopt;
        output.push_back(ops.back());
        ops.pop_back();
    }
    return output;
}

}  // namespace

QueryService::QueryService(mylib::storage::CatalogRepository& repository)
    : repository_(repository) {}

QueryResult QueryService::execute(const std::string& query_text) const {
    const auto tokens = tokenize(query_text);
    if (tokens.empty()) {
        return {QueryStatus::invalid_query, {}, "query is empty", "no tokens parsed"};
    }

    const auto rpn = to_rpn(tokens);
    if (!rpn.has_value()) {
        return {QueryStatus::invalid_query, {}, "query has invalid grouping", "rpn conversion failed"};
    }
    const auto terms = extract_terms(tokens);

    QueryResult result{};
    result.status = QueryStatus::ok;
    std::vector<ScoredRecord> scored_matches;

    for (const auto& record : repository_.list_all()) {
        std::string searchable = to_lower_copy(record.title);
        for (const auto& tag : record.tags) {
            searchable.append(" ").append(to_lower_copy(tag));
        }

        bool ok = false;
        if (evaluate_rpn(*rpn, searchable, &ok) && ok) {
            scored_matches.push_back({record, score_record(record, terms)});
        } else if (!ok) {
            return {QueryStatus::invalid_query, {}, "query expression is invalid", "rpn evaluation failed"};
        }
    }

    stable_rank(&scored_matches);
    result.matches.reserve(scored_matches.size());
    for (const auto& scored : scored_matches) {
        result.matches.push_back(scored.record);
    }
    result.diagnostics = build_diagnostics(terms, 3, 2, result.matches.size());
    return result;
}

RebuildResult QueryService::trigger_rebuild(bool is_admin, const std::string& mode) {
    if (!is_admin) {
        return {RebuildStatus::forbidden, rebuild_state_, "admin role required"};
    }
    const auto lowered = to_lower_copy(mode);
    if (lowered != "online" && lowered != "maintenance") {
        return {RebuildStatus::invalid_mode, rebuild_state_, "mode must be online or maintenance"};
    }

    rebuild_state_ = RebuildState::queued;
    rebuild_state_ = RebuildState::running;
    rebuild_state_ = RebuildState::completed;
    return {RebuildStatus::accepted, rebuild_state_, "rebuild completed"};
}

RebuildState QueryService::rebuild_state() const { return rebuild_state_; }

}  // namespace mylib::search

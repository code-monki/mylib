#include "search/query_service.hpp"

#include <algorithm>
#include <cctype>
#include <string>

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

std::optional<std::vector<std::string>> to_rpn(const std::vector<std::string>& tokens) {
    auto pop_until_left_paren = [](std::vector<std::string>& ops, std::vector<std::string>& output) -> bool {
        while (!ops.empty()) {
            const auto op = ops.back();
            ops.pop_back();
            if (op == "(") {
                return true;
            }
            output.push_back(op);
        }
        return false;
    };

    auto drain_ops_by_precedence = [](
                                      std::vector<std::string>& ops,
                                      std::vector<std::string>& output,
                                      const std::string& lowered
                                  ) {
        while (!ops.empty() && is_operator(ops.back()) &&
               precedence(ops.back()) >= precedence(lowered)) {
            output.push_back(ops.back());
            ops.pop_back();
        }
    };

    auto flush_remaining_ops = [](std::vector<std::string>& ops, std::vector<std::string>& output) -> bool {
        while (!ops.empty()) {
            if (ops.back() == "(" || ops.back() == ")") {
                return false;
            }
            output.push_back(ops.back());
            ops.pop_back();
        }
        return true;
    };

    std::vector<std::string> output;
    std::vector<std::string> ops;

    for (const auto& token : tokens) {
        const auto lowered = to_lower_copy(token);
        if (token == "(") {
            ops.push_back(token);
        } else if (token == ")") {
            if (!pop_until_left_paren(ops, output)) return std::nullopt;
        } else if (is_operator(lowered)) {
            drain_ops_by_precedence(ops, output, lowered);
            ops.push_back(lowered);
        } else {
            output.push_back(token);
        }
    }

    if (!flush_remaining_ops(ops, output)) return std::nullopt;
    return output;
}

}  // namespace

QueryService::QueryService(mylib::storage::CatalogRepository& repository)
    : repository_(repository) {}

QueryResult QueryService::execute(const std::string& query_text) const {
    const auto tokens = tokenize(query_text);
    if (tokens.empty()) {
        return {QueryStatus::invalid_query, {}, "query is empty"};
    }

    const auto rpn = to_rpn(tokens);
    if (!rpn.has_value()) {
        return {QueryStatus::invalid_query, {}, "query has invalid grouping"};
    }

    QueryResult result{};
    result.status = QueryStatus::ok;

    for (const auto& record : repository_.list_all()) {
        std::string searchable = to_lower_copy(record.title);
        for (const auto& tag : record.tags) {
            searchable.append(" ").append(to_lower_copy(tag));
        }

        bool ok = false;
        if (evaluate_rpn(*rpn, searchable, &ok) && ok) {
            result.matches.push_back(record);
        } else if (!ok) {
            return {QueryStatus::invalid_query, {}, "query expression is invalid"};
        }
    }
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

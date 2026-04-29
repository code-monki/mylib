#include "shell/shell_facade.hpp"

#include <cctype>
#include <unordered_map>

namespace mylib::shell {

ShellFacade::ShellFacade(
    mylib::security::AuthService& auth,
    mylib::search::QueryService& search,
    mylib::ingest::ImportService& ingest,
    mylib::storage::CatalogRepository& repository
)
    : auth_(auth), search_(search), ingest_(ingest), repository_(repository) {}

std::optional<mylib::security::Session> ShellFacade::login(
    const std::string& username,
    const std::string& password
) const {
    return auth_.authenticate(username, password);
}

std::vector<mylib::domain::CatalogRecord> ShellFacade::library() const { return repository_.list_all(); }

mylib::search::QueryResult ShellFacade::search_library(const std::string& query) const {
    return search_.execute(query);
}

std::optional<mylib::ingest::ImportDraft> ShellFacade::start_import(
    const std::string& id,
    const std::string& path
) const {
    return ingest_.create_draft(id, path);
}

mylib::search::RebuildResult ShellFacade::run_admin_rebuild(
    const std::string& session_token,
    const std::string& mode
) {
    const bool authorized = auth_.authorize(session_token, mylib::security::Role::admin, "default");
    return search_.trigger_rebuild(authorized, mode);
}

std::vector<std::string> ShellFacade::split_args(const std::string& command_line) {
    std::vector<std::string> tokens;
    std::string current;
    bool in_quotes = false;

    for (char c : command_line) {
        if (c == '"') {
            in_quotes = !in_quotes;
            continue;
        }
        if (std::isspace(static_cast<unsigned char>(c)) && !in_quotes) {
            if (!current.empty()) {
                tokens.push_back(current);
                current.clear();
            }
            continue;
        }
        current.push_back(c);
    }
    if (!current.empty()) {
        tokens.push_back(current);
    }
    return tokens;
}

std::string ShellFacade::join_args(const std::vector<std::string>& args, std::size_t begin_idx) {
    std::string out;
    for (std::size_t i = begin_idx; i < args.size(); ++i) {
        if (!out.empty()) out.push_back(' ');
        out.append(args[i]);
    }
    return out;
}

bool ShellFacade::parse_bool_arg(const std::string& value, bool* out) {
    if (value == "true" || value == "1") {
        *out = true;
        return true;
    }
    if (value == "false" || value == "0") {
        *out = false;
        return true;
    }
    return false;
}

ShellFacade::CommandKind ShellFacade::parse_command_kind(const std::string& command) {
    static const std::unordered_map<std::string, CommandKind> kCommands = {
        {"help", CommandKind::help},
        {"login", CommandKind::login},
        {"library", CommandKind::library},
        {"search", CommandKind::search},
        {"import-draft", CommandKind::import_draft},
        {"import-commit", CommandKind::import_commit},
        {"rebuild", CommandKind::rebuild},
    };
    const auto it = kCommands.find(command);
    if (it == kCommands.end()) return CommandKind::unknown;
    return it->second;
}

ShellCommandResult ShellFacade::handle_help() const {
    return {
        ShellCommandStatus::ok,
        "commands: help, login <user> <pass>, library, search <query>, import-draft <id> <path>, import-commit <allow_dup> <apply_hint>, rebuild <mode>",
        0
    };
}

ShellCommandResult ShellFacade::handle_login(const std::vector<std::string>& args) {
    if (args.size() != 3) return {ShellCommandStatus::invalid_arguments, "usage: login <user> <pass>", 0};
    current_session_ = login(args[1], args[2]);
    if (!current_session_.has_value()) return {ShellCommandStatus::unauthorized, "authentication failed", 0};
    return {ShellCommandStatus::ok, "login successful", 0};
}

ShellCommandResult ShellFacade::handle_library() const {
    const auto records = library();
    return {ShellCommandStatus::ok, "library listed", static_cast<int>(records.size())};
}

ShellCommandResult ShellFacade::handle_search(const std::vector<std::string>& args) const {
    if (args.size() < 2) return {ShellCommandStatus::invalid_arguments, "usage: search <query>", 0};
    const auto result = search_library(join_args(args, 1));
    if (result.status != mylib::search::QueryStatus::ok) return {ShellCommandStatus::failed, result.message, 0};
    return {ShellCommandStatus::ok, "search completed", static_cast<int>(result.matches.size())};
}

ShellCommandResult ShellFacade::handle_import_draft(const std::vector<std::string>& args) {
    if (args.size() != 3) return {ShellCommandStatus::invalid_arguments, "usage: import-draft <id> <path>", 0};
    current_draft_ = start_import(args[1], args[2]);
    if (!current_draft_.has_value()) return {ShellCommandStatus::failed, "unable to create import draft", 0};
    return {ShellCommandStatus::ok, "import draft created", 0};
}

ShellCommandResult ShellFacade::handle_import_commit(const std::vector<std::string>& args) {
    if (args.size() != 3) {
        return {ShellCommandStatus::invalid_arguments, "usage: import-commit <allow_dup> <apply_hint>", 0};
    }
    if (!current_draft_.has_value()) return {ShellCommandStatus::failed, "no active draft to commit", 0};

    bool allow_dup = false;
    bool apply_hint = false;
    if (!parse_bool_arg(args[1], &allow_dup) || !parse_bool_arg(args[2], &apply_hint)) {
        return {ShellCommandStatus::invalid_arguments, "boolean args must be true/false or 1/0", 0};
    }

    const auto commit = ingest_.commit_draft(*current_draft_, allow_dup, apply_hint);
    if (commit.status != mylib::ingest::ImportCommitStatus::imported) {
        return {ShellCommandStatus::failed, commit.message, 0};
    }
    current_draft_.reset();
    return {ShellCommandStatus::ok, "import committed", 0};
}

ShellCommandResult ShellFacade::handle_rebuild(const std::vector<std::string>& args) {
    if (args.size() != 2) return {ShellCommandStatus::invalid_arguments, "usage: rebuild <online|maintenance>", 0};
    if (!current_session_.has_value()) return {ShellCommandStatus::unauthorized, "login required", 0};

    const auto rebuild = run_admin_rebuild(current_session_->token, args[1]);
    if (rebuild.status != mylib::search::RebuildStatus::accepted) {
        return {ShellCommandStatus::failed, rebuild.message, 0};
    }
    return {ShellCommandStatus::ok, "rebuild completed", 0};
}

ShellCommandResult ShellFacade::execute_command(const std::string& command_line) {
    const auto args = split_args(command_line);
    if (args.empty()) return {ShellCommandStatus::invalid_command, "empty command", 0};

    switch (parse_command_kind(args[0])) {
        case CommandKind::help:
            return handle_help();
        case CommandKind::login:
            return handle_login(args);
        case CommandKind::library:
            return handle_library();
        case CommandKind::search:
            return handle_search(args);
        case CommandKind::import_draft:
            return handle_import_draft(args);
        case CommandKind::import_commit:
            return handle_import_commit(args);
        case CommandKind::rebuild:
            return handle_rebuild(args);
        case CommandKind::unknown:
            return {ShellCommandStatus::invalid_command, "unknown command", 0};
    }
    return {ShellCommandStatus::invalid_command, "unknown command", 0};
}

}  // namespace mylib::shell

#pragma once

#include "ingest/import_service.hpp"
#include "search/query_service.hpp"
#include "security/auth_service.hpp"
#include "storage/catalog_repository.hpp"

#include <optional>
#include <string>
#include <vector>

namespace mylib::shell {

enum class ShellCommandStatus {
    ok,
    invalid_command,
    invalid_arguments,
    unauthorized,
    failed,
};

struct ShellCommandResult {
    ShellCommandStatus status = ShellCommandStatus::invalid_command;
    std::string message;
    int result_count = 0;
};

class ShellFacade {
public:
    ShellFacade(
        mylib::security::AuthService& auth,
        mylib::search::QueryService& search,
        mylib::ingest::ImportService& ingest,
        mylib::storage::CatalogRepository& repository
    );

    std::optional<mylib::security::Session> login(
        const std::string& username,
        const std::string& password
    ) const;
    std::vector<mylib::domain::CatalogRecord> library() const;
    mylib::search::QueryResult search_library(const std::string& query) const;
    std::optional<mylib::ingest::ImportDraft> start_import(
        const std::string& id,
        const std::string& path
    ) const;
    mylib::search::RebuildResult run_admin_rebuild(
        const std::string& session_token,
        const std::string& mode
    );
    ShellCommandResult execute_command(const std::string& command_line);

private:
    enum class CommandKind {
        help,
        login,
        library,
        search,
        import_draft,
        import_commit,
        rebuild,
        unknown,
    };

    static std::vector<std::string> split_args(const std::string& command_line);
    static std::string join_args(const std::vector<std::string>& args, std::size_t begin_idx);
    static bool parse_bool_arg(const std::string& value, bool* out);
    static CommandKind parse_command_kind(const std::string& command);
    ShellCommandResult handle_help() const;
    ShellCommandResult handle_login(const std::vector<std::string>& args);
    ShellCommandResult handle_library() const;
    ShellCommandResult handle_search(const std::vector<std::string>& args) const;
    ShellCommandResult handle_import_draft(const std::vector<std::string>& args);
    ShellCommandResult handle_import_commit(const std::vector<std::string>& args);
    ShellCommandResult handle_rebuild(const std::vector<std::string>& args);

    mylib::security::AuthService& auth_;
    mylib::search::QueryService& search_;
    mylib::ingest::ImportService& ingest_;
    mylib::storage::CatalogRepository& repository_;
    std::optional<mylib::security::Session> current_session_;
    std::optional<mylib::ingest::ImportDraft> current_draft_;
};

}  // namespace mylib::shell

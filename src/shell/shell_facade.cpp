#include "shell/shell_facade.hpp"

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

}  // namespace mylib::shell

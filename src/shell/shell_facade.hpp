#pragma once

#include "ingest/import_service.hpp"
#include "search/query_service.hpp"
#include "security/auth_service.hpp"
#include "storage/catalog_repository.hpp"

#include <optional>
#include <string>
#include <vector>

namespace mylib::shell {

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

private:
    mylib::security::AuthService& auth_;
    mylib::search::QueryService& search_;
    mylib::ingest::ImportService& ingest_;
    mylib::storage::CatalogRepository& repository_;
};

}  // namespace mylib::shell

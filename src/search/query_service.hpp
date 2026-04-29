#pragma once

#include "domain/catalog_record.hpp"
#include "storage/catalog_repository.hpp"

#include <optional>
#include <string>
#include <vector>

namespace mylib::search {

enum class QueryStatus {
    ok,
    invalid_query,
};

struct QueryResult {
    QueryStatus status = QueryStatus::ok;
    std::vector<mylib::domain::CatalogRecord> matches;
    std::string message;
};

enum class RebuildState {
    idle,
    queued,
    running,
    completed,
    failed,
};

enum class RebuildStatus {
    accepted,
    forbidden,
    invalid_mode,
};

struct RebuildResult {
    RebuildStatus status = RebuildStatus::forbidden;
    RebuildState state = RebuildState::idle;
    std::string message;
};

class QueryService {
public:
    explicit QueryService(mylib::storage::CatalogRepository& repository);

    QueryResult execute(const std::string& query_text) const;
    RebuildResult trigger_rebuild(bool is_admin, const std::string& mode);
    RebuildState rebuild_state() const;

private:
    mylib::storage::CatalogRepository& repository_;
    RebuildState rebuild_state_ = RebuildState::idle;
};

}  // namespace mylib::search

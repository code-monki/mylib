#pragma once

#include "domain/catalog_record.hpp"

#include <optional>
#include <string>
#include <vector>

namespace mylib::storage {

enum class SaveStatus {
    ok,
    validation_failed,
    already_exists,
    not_found,
    version_conflict,
    io_error,
};

struct SaveResult {
    SaveStatus status = SaveStatus::ok;
    std::optional<mylib::domain::CatalogRecord> record;
};

enum class DeleteStatus {
    deleted,
    not_found,
    io_error,
};

struct DeleteResult {
    DeleteStatus status = DeleteStatus::not_found;
    std::optional<mylib::domain::CatalogRecord> record;
};

class CatalogRepository {
public:
    virtual ~CatalogRepository() = default;

    virtual SaveResult create(const mylib::domain::CatalogRecord& record) = 0;
    virtual std::optional<mylib::domain::CatalogRecord> get_by_id(const std::string& id) const = 0;
    virtual SaveResult update(
        const mylib::domain::CatalogRecord& updated_record,
        int expected_version
    ) = 0;
    virtual DeleteResult delete_by_id(const std::string& id) = 0;
    virtual std::vector<mylib::domain::CatalogRecord> list_all() const = 0;
};

}  // namespace mylib::storage

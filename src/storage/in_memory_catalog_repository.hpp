#pragma once

#include "storage/catalog_repository.hpp"

#include <unordered_map>

namespace mylib::storage {

class InMemoryCatalogRepository final : public CatalogRepository {
public:
    SaveResult create(const mylib::domain::CatalogRecord& record) override;
    std::optional<mylib::domain::CatalogRecord> get_by_id(const std::string& id) const override;
    SaveResult update(
        const mylib::domain::CatalogRecord& updated_record,
        int expected_version
    ) override;
    DeleteResult delete_by_id(const std::string& id) override;
    std::vector<mylib::domain::CatalogRecord> list_all() const override;

private:
    std::unordered_map<std::string, mylib::domain::CatalogRecord> records_;
};

}  // namespace mylib::storage

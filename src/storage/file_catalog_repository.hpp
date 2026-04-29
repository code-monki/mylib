#pragma once

#include "storage/catalog_repository.hpp"

#include <functional>
#include <string>
#include <unordered_map>

namespace mylib::storage {

class FileCatalogRepository final : public CatalogRepository {
public:
    using IoErrorHook = std::function<void(const std::string& action, const std::string& detail)>;

    explicit FileCatalogRepository(
        std::string storage_file,
        IoErrorHook io_error_hook = {},
        bool force_persist_failure_for_test = false
    );

    SaveResult create(const mylib::domain::CatalogRecord& record) override;
    std::optional<mylib::domain::CatalogRecord> get_by_id(const std::string& id) const override;
    SaveResult update(const mylib::domain::CatalogRecord& updated_record, int expected_version) override;
    DeleteResult delete_by_id(const std::string& id) override;
    std::vector<mylib::domain::CatalogRecord> list_all() const override;

private:
    bool load_from_disk();
    bool flush_to_disk(const std::unordered_map<std::string, mylib::domain::CatalogRecord>& records) const;
    void emit_io_error(const std::string& action, const std::string& detail) const;
    static std::string encode_field(const std::string& value);
    static std::string decode_field(const std::string& value);

    std::string storage_file_;
    std::unordered_map<std::string, mylib::domain::CatalogRecord> records_;
    IoErrorHook io_error_hook_;
    bool force_persist_failure_for_test_ = false;
};

}  // namespace mylib::storage

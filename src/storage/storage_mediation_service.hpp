#pragma once

#include "storage/catalog_repository.hpp"

#include <string>

namespace mylib::storage {

enum class FileAvailability {
    available,
    missing,
    record_not_found,
    no_source_path,
};

enum class RelinkStatus {
    relinked,
    record_not_found,
    target_missing,
};

enum class ReaderOpenStatus {
    ready,
    record_not_found,
    file_missing,
    no_source_path,
};

enum class RemovalMode {
    catalog_only,
    delete_from_disk,
};

enum class RemovalStatus {
    removed_catalog_only,
    removed_and_file_deleted,
    record_not_found,
    file_delete_failed,
};

struct ReaderOpenRequest {
    ReaderOpenStatus status = ReaderOpenStatus::record_not_found;
    std::string file_path;
    std::string reader_hint;
};

struct RemovalResult {
    RemovalStatus status = RemovalStatus::record_not_found;
    std::string file_path;
};

class StorageMediationService {
public:
    explicit StorageMediationService(CatalogRepository& repository);

    FileAvailability check_file_status(const std::string& record_id) const;
    RelinkStatus relink_record(const std::string& record_id, const std::string& new_path);
    ReaderOpenRequest build_open_request(
        const std::string& record_id,
        const std::string& preferred_reader
    ) const;
    RemovalResult remove_record(const std::string& record_id, RemovalMode mode);

private:
    CatalogRepository& repository_;
};

}  // namespace mylib::storage

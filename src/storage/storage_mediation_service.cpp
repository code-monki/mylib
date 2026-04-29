#include "storage/storage_mediation_service.hpp"

#include <filesystem>

namespace mylib::storage {

StorageMediationService::StorageMediationService(CatalogRepository& repository)
    : repository_(repository) {}

FileAvailability StorageMediationService::check_file_status(const std::string& record_id) const {
    const auto record = repository_.get_by_id(record_id);
    if (!record.has_value()) {
        return FileAvailability::record_not_found;
    }
    if (record->source_path.empty()) {
        return FileAvailability::no_source_path;
    }
    if (!std::filesystem::exists(record->source_path)) {
        return FileAvailability::missing;
    }
    return FileAvailability::available;
}

RelinkStatus StorageMediationService::relink_record(
    const std::string& record_id,
    const std::string& new_path
) {
    const auto record = repository_.get_by_id(record_id);
    if (!record.has_value()) {
        return RelinkStatus::record_not_found;
    }

    if (!std::filesystem::exists(new_path)) {
        return RelinkStatus::target_missing;
    }

    auto updated = *record;
    updated.source_path = new_path;
    const auto saved = repository_.update(updated, record->version);
    if (saved.status != SaveStatus::ok) {
        return RelinkStatus::record_not_found;
    }
    return RelinkStatus::relinked;
}

ReaderOpenRequest StorageMediationService::build_open_request(
    const std::string& record_id,
    const std::string& preferred_reader
) const {
    const auto record = repository_.get_by_id(record_id);
    if (!record.has_value()) {
        return {ReaderOpenStatus::record_not_found, "", preferred_reader};
    }
    if (record->source_path.empty()) {
        return {ReaderOpenStatus::no_source_path, "", preferred_reader};
    }
    if (!std::filesystem::exists(record->source_path)) {
        return {ReaderOpenStatus::file_missing, "", preferred_reader};
    }
    return {ReaderOpenStatus::ready, record->source_path, preferred_reader};
}

RemovalResult StorageMediationService::remove_record(const std::string& record_id, RemovalMode mode) {
    const auto deleted = repository_.delete_by_id(record_id);
    if (deleted.status == DeleteStatus::not_found || !deleted.record.has_value()) {
        return {RemovalStatus::record_not_found, ""};
    }

    const auto path = deleted.record->source_path;
    if (mode == RemovalMode::catalog_only || path.empty()) {
        return {RemovalStatus::removed_catalog_only, path};
    }

    std::error_code ec;
    const bool removed = std::filesystem::remove(path, ec);
    if (!removed || ec) {
        return {RemovalStatus::file_delete_failed, path};
    }
    return {RemovalStatus::removed_and_file_deleted, path};
}

}  // namespace mylib::storage

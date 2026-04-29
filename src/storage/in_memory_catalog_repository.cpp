#include "storage/in_memory_catalog_repository.hpp"

#include "domain/catalog_record.hpp"

namespace mylib::storage {

SaveResult InMemoryCatalogRepository::create(const mylib::domain::CatalogRecord& record) {
    const auto normalized = mylib::domain::normalize_catalog_record(record);
    if (!normalized.has_value()) {
        return {SaveStatus::validation_failed, std::nullopt};
    }

    if (records_.contains(normalized->id)) {
        return {SaveStatus::already_exists, std::nullopt};
    }

    auto persisted = *normalized;
    persisted.version = 1;
    records_[persisted.id] = persisted;
    return {SaveStatus::ok, persisted};
}

std::optional<mylib::domain::CatalogRecord> InMemoryCatalogRepository::get_by_id(
    const std::string& id
) const {
    const auto it = records_.find(id);
    if (it == records_.end()) {
        return std::nullopt;
    }
    return it->second;
}

SaveResult InMemoryCatalogRepository::update(
    const mylib::domain::CatalogRecord& updated_record,
    int expected_version
) {
    const auto normalized = mylib::domain::normalize_catalog_record(updated_record);
    if (!normalized.has_value()) {
        return {SaveStatus::validation_failed, std::nullopt};
    }

    const auto it = records_.find(normalized->id);
    if (it == records_.end()) {
        return {SaveStatus::not_found, std::nullopt};
    }

    if (it->second.version != expected_version) {
        return {SaveStatus::version_conflict, it->second};
    }

    auto persisted = *normalized;
    persisted.version = it->second.version + 1;
    it->second = persisted;
    return {SaveStatus::ok, persisted};
}

DeleteResult InMemoryCatalogRepository::delete_by_id(const std::string& id) {
    const auto it = records_.find(id);
    if (it == records_.end()) {
        return {DeleteStatus::not_found, std::nullopt};
    }

    auto deleted = it->second;
    records_.erase(it);
    return {DeleteStatus::deleted, deleted};
}

std::vector<mylib::domain::CatalogRecord> InMemoryCatalogRepository::list_all() const {
    std::vector<mylib::domain::CatalogRecord> out;
    out.reserve(records_.size());
    for (const auto& [_, value] : records_) {
        out.push_back(value);
    }
    return out;
}

}  // namespace mylib::storage

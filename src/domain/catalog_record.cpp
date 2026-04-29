#include "domain/catalog_record.hpp"

#include <algorithm>
#include <cctype>
#include <set>

namespace mylib::domain {

namespace {

std::string trim_copy(const std::string& value) {
    auto begin = value.begin();
    while (begin != value.end() && std::isspace(static_cast<unsigned char>(*begin))) {
        ++begin;
    }

    auto end = value.end();
    while (end != begin && std::isspace(static_cast<unsigned char>(*(end - 1)))) {
        --end;
    }

    return std::string(begin, end);
}

}  // namespace

std::vector<ValidationError> validate_catalog_record(const CatalogRecord& record) {
    std::vector<ValidationError> errors;

    if (trim_copy(record.id).empty()) {
        errors.push_back({"id", "id must not be empty"});
    }

    if (trim_copy(record.title).empty()) {
        errors.push_back({"title", "title must not be empty"});
    }

    if (record.version < 1) {
        errors.push_back({"version", "version must be >= 1"});
    }

    if (!record.source_fingerprint.empty() && record.source_fingerprint.size() < 8) {
        errors.push_back({"source_fingerprint", "fingerprint is unexpectedly short"});
    }

    std::set<std::string> unique_tags;
    for (const auto& tag : record.tags) {
        const auto normalized = trim_copy(tag);
        if (normalized.empty()) {
            errors.push_back({"tags", "tags must not include empty values"});
            continue;
        }
        if (!unique_tags.insert(normalized).second) {
            errors.push_back({"tags", "tags must not include duplicates"});
        }
    }

    return errors;
}

std::optional<CatalogRecord> normalize_catalog_record(const CatalogRecord& record) {
    CatalogRecord normalized = record;
    normalized.id = trim_copy(normalized.id);
    normalized.title = trim_copy(normalized.title);
    normalized.source_path = trim_copy(normalized.source_path);
    normalized.source_fingerprint = trim_copy(normalized.source_fingerprint);

    std::vector<std::string> tags;
    tags.reserve(normalized.tags.size());
    std::set<std::string> seen;
    for (const auto& tag : normalized.tags) {
        const auto trimmed = trim_copy(tag);
        if (trimmed.empty()) {
            continue;
        }
        if (seen.insert(trimmed).second) {
            tags.push_back(trimmed);
        }
    }
    normalized.tags = std::move(tags);

    if (!validate_catalog_record(normalized).empty()) {
        return std::nullopt;
    }
    return normalized;
}

}  // namespace mylib::domain

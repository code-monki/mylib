#pragma once

#include <optional>
#include <string>
#include <vector>

namespace mylib::domain {

struct CatalogRecord {
    std::string id;
    std::string title;
    std::vector<std::string> tags;
    std::string source_path;
    std::string source_fingerprint;
    int version = 1;
};

struct ValidationError {
    std::string field;
    std::string message;
};

std::vector<ValidationError> validate_catalog_record(const CatalogRecord& record);
std::optional<CatalogRecord> normalize_catalog_record(const CatalogRecord& record);

}  // namespace mylib::domain

#pragma once

#include "storage/catalog_repository.hpp"

#include <optional>
#include <string>
#include <vector>

namespace mylib::ingest {

struct MetadataHint {
    std::string field;
    std::string value;
    std::string source;
};

struct ImportDraft {
    std::string id;
    std::string title;
    std::vector<std::string> tags;
    std::string source_path;
    std::string source_fingerprint;
    std::optional<std::string> duplicate_of_id;
    std::vector<MetadataHint> hints;
};

enum class ImportCommitStatus {
    imported,
    duplicate_requires_decision,
    validation_failed,
    io_error,
};

struct ImportCommitResult {
    ImportCommitStatus status = ImportCommitStatus::io_error;
    std::optional<mylib::domain::CatalogRecord> record;
    std::optional<std::string> duplicate_of_id;
    std::string message;
};

class ImportService {
public:
    explicit ImportService(mylib::storage::CatalogRepository& repository);

    std::optional<ImportDraft> create_draft(const std::string& record_id, const std::string& source_path) const;
    ImportCommitResult commit_draft(
        const ImportDraft& draft,
        bool allow_duplicate_import,
        bool apply_title_hint
    );

private:
    mylib::storage::CatalogRepository& repository_;
};

}  // namespace mylib::ingest

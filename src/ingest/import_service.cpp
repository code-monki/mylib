#include "ingest/import_service.hpp"

#include "ingest/metadata_providers.hpp"
#include "ingest/pdf_probe.hpp"

#include <filesystem>

namespace mylib::ingest {

ImportService::ImportService(mylib::storage::CatalogRepository& repository)
    : repository_(repository) {}

std::optional<ImportDraft> ImportService::create_draft(
    const std::string& record_id,
    const std::string& source_path
) const {
    std::vector<std::uint8_t> bytes;
    try {
        bytes = read_file_bytes(source_path);
    } catch (...) {
        return std::nullopt;
    }
    if (bytes.empty()) {
        return std::nullopt;
    }

    ImportDraft draft{};
    draft.id = record_id;
    draft.title = "Untitled import";
    draft.source_path = source_path;
    draft.source_fingerprint = fingerprint_hex_fnv1a64(bytes);

    const auto stem = std::filesystem::path(source_path).stem().string();
    const auto signals = probe_pdf_signals(bytes);
    if (!stem.empty()) draft.hints.push_back({"title", stem, "filename"});
    if (signals.has_title_metadata) draft.hints.push_back({"title", stem, "pdf-title-marker"});
    const auto provider_hints = collect_provider_hints(source_path, stem, signals);
    draft.hints.insert(draft.hints.end(), provider_hints.begin(), provider_hints.end());

    for (const auto& record : repository_.list_all()) {
        if (!record.source_fingerprint.empty() &&
            record.source_fingerprint == draft.source_fingerprint) {
            draft.duplicate_of_id = record.id;
            break;
        }
    }

    return draft;
}

ImportCommitResult ImportService::commit_draft(
    const ImportDraft& draft,
    bool allow_duplicate_import,
    bool apply_title_hint
) {
    if (draft.duplicate_of_id.has_value() && !allow_duplicate_import) {
        return {
            ImportCommitStatus::duplicate_requires_decision,
            std::nullopt,
            draft.duplicate_of_id,
            "duplicate detected: explicit user decision required",
        };
    }

    mylib::domain::CatalogRecord record{};
    record.id = draft.id;
    record.title = draft.title;
    record.tags = draft.tags;
    record.source_path = draft.source_path;
    record.source_fingerprint = draft.source_fingerprint;

    if (apply_title_hint) {
        for (const auto& hint : draft.hints) {
            if (hint.field == "title" && !hint.value.empty()) {
                record.title = hint.value;
                break;
            }
        }
    }

    const auto saved = repository_.create(record);
    switch (saved.status) {
        case mylib::storage::SaveStatus::ok:
            return {
                ImportCommitStatus::imported,
                saved.record,
                std::nullopt,
                "record imported",
            };
        case mylib::storage::SaveStatus::validation_failed:
            return {
                ImportCommitStatus::validation_failed,
                std::nullopt,
                std::nullopt,
                "record failed validation",
            };
        default:
            return {
                ImportCommitStatus::io_error,
                std::nullopt,
                std::nullopt,
                "import failed to persist",
            };
    }
}

}  // namespace mylib::ingest

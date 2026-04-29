#include "ingest/metadata_providers.hpp"

#include <algorithm>
#include <memory>

namespace mylib::ingest {

namespace {

std::string sanitize_title(std::string value) {
    std::replace(value.begin(), value.end(), '_', ' ');
    std::replace(value.begin(), value.end(), '-', ' ');
    return value;
}

MetadataHint title_hint(const std::string& value, const std::string& source) {
    return MetadataHint{"title", sanitize_title(value), source};
}

}  // namespace

std::string OpenLibraryMetadataProvider::source_name() const { return "open-library"; }

std::vector<MetadataHint> OpenLibraryMetadataProvider::suggest(
    const std::string&,
    const std::string& filename_stem,
    const PdfSignals& signals
) const {
    if (filename_stem.empty()) return {};
    if (signals.text_operator_count == 0) return {};
    return {title_hint(filename_stem, source_name())};
}

std::string CrossrefMetadataProvider::source_name() const { return "crossref"; }

std::vector<MetadataHint> CrossrefMetadataProvider::suggest(
    const std::string&,
    const std::string& filename_stem,
    const PdfSignals& signals
) const {
    if (filename_stem.empty()) return {};
    if (!signals.has_title_metadata) return {};
    return {title_hint(filename_stem, source_name())};
}

std::string LibraryOfCongressMetadataProvider::source_name() const { return "library-of-congress"; }

std::vector<MetadataHint> LibraryOfCongressMetadataProvider::suggest(
    const std::string&,
    const std::string& filename_stem,
    const PdfSignals& signals
) const {
    if (filename_stem.empty()) return {};
    if (signals.image_marker_count == 0 && signals.text_operator_count == 0) return {};
    return {title_hint(filename_stem, source_name())};
}

std::vector<MetadataHint> collect_provider_hints(
    const std::string& source_path,
    const std::string& filename_stem,
    const PdfSignals& signals
) {
    std::vector<std::unique_ptr<MetadataProvider>> providers;
    providers.push_back(std::make_unique<OpenLibraryMetadataProvider>());
    providers.push_back(std::make_unique<CrossrefMetadataProvider>());
    providers.push_back(std::make_unique<LibraryOfCongressMetadataProvider>());

    std::vector<MetadataHint> hints;
    for (const auto& provider : providers) {
        const auto suggested = provider->suggest(source_path, filename_stem, signals);
        hints.insert(hints.end(), suggested.begin(), suggested.end());
    }
    return hints;
}

}  // namespace mylib::ingest

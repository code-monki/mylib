#pragma once

#include "ingest/import_service.hpp"
#include "ingest/pdf_probe.hpp"

#include <string>
#include <vector>

namespace mylib::ingest {

class MetadataProvider {
public:
    virtual ~MetadataProvider() = default;
    virtual std::string source_name() const = 0;
    virtual std::vector<MetadataHint> suggest(
        const std::string& source_path,
        const std::string& filename_stem,
        const PdfSignals& signals
    ) const = 0;
};

class OpenLibraryMetadataProvider final : public MetadataProvider {
public:
    std::string source_name() const override;
    std::vector<MetadataHint> suggest(
        const std::string& source_path,
        const std::string& filename_stem,
        const PdfSignals& signals
    ) const override;
};

class CrossrefMetadataProvider final : public MetadataProvider {
public:
    std::string source_name() const override;
    std::vector<MetadataHint> suggest(
        const std::string& source_path,
        const std::string& filename_stem,
        const PdfSignals& signals
    ) const override;
};

class LibraryOfCongressMetadataProvider final : public MetadataProvider {
public:
    std::string source_name() const override;
    std::vector<MetadataHint> suggest(
        const std::string& source_path,
        const std::string& filename_stem,
        const PdfSignals& signals
    ) const override;
};

std::vector<MetadataHint> collect_provider_hints(
    const std::string& source_path,
    const std::string& filename_stem,
    const PdfSignals& signals
);

}  // namespace mylib::ingest

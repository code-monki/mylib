#include "ocr/ocr_boundary_service.hpp"

#include "ingest/pdf_probe.hpp"

namespace mylib::ocr {

OcrAssessment OcrBoundaryService::assess_document(const std::string& pdf_path) const {
    std::vector<std::uint8_t> bytes;
    try {
        bytes = mylib::ingest::read_file_bytes(pdf_path);
    } catch (...) {
        return {OcrDecision::unavailable, "file could not be read", "none"};
    }

    const auto signals = mylib::ingest::probe_pdf_signals(bytes);
    if (signals.byte_size == 0) {
        return {OcrDecision::unavailable, "empty document", "none"};
    }

    const auto text_count = static_cast<double>(signals.text_operator_count);
    const auto image_count = static_cast<double>(signals.image_marker_count);
    const auto image_bias = (image_count + 1.0) / (text_count + 1.0);

    const bool heavy_image_doc = image_bias > 1.8 && signals.byte_size > (1024 * 1024);
    const bool scanned_profile =
        !signals.has_title_metadata && signals.image_marker_count > 80 &&
        signals.byte_size > (5 * 1024 * 1024);

    if (heavy_image_doc || scanned_profile) {
        return {OcrDecision::required, "image-dominant document profile", "ocr-needed"};
    }
    return {OcrDecision::not_required, "text layer appears sufficient", "embedded-text"};
}

}  // namespace mylib::ocr

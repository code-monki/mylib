#pragma once

#include <string>

namespace mylib::ocr {

enum class OcrDecision {
    not_required,
    required,
    unavailable,
};

struct OcrAssessment {
    OcrDecision decision = OcrDecision::unavailable;
    std::string reason;
    std::string provenance;
};

class OcrBoundaryService {
public:
    OcrAssessment assess_document(const std::string& pdf_path) const;
};

}  // namespace mylib::ocr

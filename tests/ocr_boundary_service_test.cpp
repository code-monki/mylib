#include "ocr/ocr_boundary_service.hpp"

#include <iostream>
#include <string>

namespace {
int failures = 0;

void expect(bool condition, const std::string& message) {
    if (!condition) {
        ++failures;
        std::cerr << "FAIL: " << message << '\n';
    }
}

#ifndef MYLIB_REPO_ROOT
#define MYLIB_REPO_ROOT "."
#endif

std::string fixture_path(const std::string& relative) {
    return std::string(MYLIB_REPO_ROOT) + "/" + relative;
}

void test_ocr_assessment_profiles() {
    mylib::ocr::OcrBoundaryService ocr;

    auto normal = ocr.assess_document(fixture_path("tests/fixtures/pdfs/normal.pdf"));
    expect(
        normal.decision == mylib::ocr::OcrDecision::not_required,
        "normal fixture should not require OCR"
    );

    auto cursed = ocr.assess_document(fixture_path("tests/fixtures/pdfs/cursed.pdf"));
    expect(cursed.decision == mylib::ocr::OcrDecision::required, "cursed fixture should require OCR");
}
}  // namespace

int main() {
    test_ocr_assessment_profiles();
    if (failures > 0) {
        std::cerr << failures << " OCR boundary test(s) failed\n";
        return 1;
    }
    std::cout << "All OCR boundary tests passed\n";
    return 0;
}

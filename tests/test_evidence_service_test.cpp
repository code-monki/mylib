#include "quality/test_evidence_service.hpp"

#include <iostream>
#include <string>

namespace {
int failures = 0;
void expect(bool cond, const std::string& msg) {
    if (!cond) {
        ++failures;
        std::cerr << "FAIL: " << msg << '\n';
    }
}

void test_summary_and_report() {
    mylib::quality::TestEvidenceService svc;
    svc.record({"TP-INGEST-001", true, 0.8});
    svc.record({"TP-SEARCH-001", true, 1.2});
    svc.record({"TP-OCR-001", false, 0.6});

    const auto summary = svc.summarize();
    expect(summary.total == 3, "total count should be 3");
    expect(summary.passed == 2, "passed count should be 2");
    expect(summary.failed == 1, "failed count should be 1");
    expect(summary.total_duration_seconds > 2.5 && summary.total_duration_seconds < 2.7, "duration should sum");

    const auto report = svc.render_report();
    expect(report.find("evidence_total=3") != std::string::npos, "report should include total");
    expect(report.find("failed=1") != std::string::npos, "report should include failed count");
}
}  // namespace

int main() {
    test_summary_and_report();
    if (failures > 0) {
        std::cerr << failures << " test evidence test(s) failed\n";
        return 1;
    }
    std::cout << "All test evidence service tests passed\n";
    return 0;
}

#include "quality/test_evidence_service.hpp"

#include <iomanip>
#include <sstream>

namespace mylib::quality {

void TestEvidenceService::record(const TestEvidence& evidence) { entries_.push_back(evidence); }

EvidenceSummary TestEvidenceService::summarize() const {
    EvidenceSummary s{};
    s.total = static_cast<int>(entries_.size());
    for (const auto& e : entries_) {
        if (e.passed) {
            ++s.passed;
        } else {
            ++s.failed;
        }
        s.total_duration_seconds += e.duration_seconds;
    }
    return s;
}

std::string TestEvidenceService::render_report() const {
    const auto s = summarize();
    std::ostringstream out;
    out << "evidence_total=" << s.total
        << ", passed=" << s.passed
        << ", failed=" << s.failed
        << ", total_duration=" << std::fixed << std::setprecision(2) << s.total_duration_seconds;
    return out.str();
}

}  // namespace mylib::quality

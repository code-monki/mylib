#pragma once

#include <string>
#include <vector>

namespace mylib::quality {

struct TestEvidence {
    std::string test_id;
    bool passed = false;
    double duration_seconds = 0.0;
};

struct EvidenceSummary {
    int total = 0;
    int passed = 0;
    int failed = 0;
    double total_duration_seconds = 0.0;
};

class TestEvidenceService {
public:
    void record(const TestEvidence& evidence);
    EvidenceSummary summarize() const;
    std::string render_report() const;

private:
    std::vector<TestEvidence> entries_;
};

}  // namespace mylib::quality

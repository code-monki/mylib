#include "observability/audit_observability_service.hpp"

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

void test_partition_and_redaction() {
    mylib::observability::AuditObservabilityService svc;
    svc.record_audit("login", "alice", "tenant-a", "password=hunter2 token=abc");
    svc.record_ops("rebuild", "tenant-a", "secret=xyz action=run");

    const auto audits = svc.audit_events();
    const auto ops = svc.ops_events();
    expect(audits.size() == 1, "one audit event expected");
    expect(ops.size() == 1, "one ops event expected");
    expect(audits[0].detail.find("<redacted>") != std::string::npos, "audit detail should be redacted");
    expect(ops[0].detail.find("<redacted>") != std::string::npos, "ops detail should be redacted");
}
}  // namespace

int main() {
    test_partition_and_redaction();
    if (failures > 0) {
        std::cerr << failures << " audit/obslog test(s) failed\n";
        return 1;
    }
    std::cout << "All audit/observability tests passed\n";
    return 0;
}

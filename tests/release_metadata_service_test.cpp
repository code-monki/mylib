#include "release/release_metadata_service.hpp"

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

#ifndef MYLIB_REPO_ROOT
#define MYLIB_REPO_ROOT "."
#endif

void test_metadata_shape() {
    mylib::release::ReleaseMetadataService svc;
    const auto meta = svc.metadata();
    expect(!meta.version.empty(), "version should not be empty");
    expect(!meta.build_id.empty(), "build id should not be empty");
    expect(meta.required_artifacts.size() >= 2, "required artifacts should be populated");
}

void test_packaging_baseline_files_present() {
    mylib::release::ReleaseMetadataService svc;
    const auto check = svc.verify_required_artifacts(MYLIB_REPO_ROOT);
    expect(check.ok, "LICENSE/NOTICE should exist for packaging baseline");
    expect(check.missing.empty(), "no required artifacts should be missing");
}
}  // namespace

int main() {
    test_metadata_shape();
    test_packaging_baseline_files_present();
    if (failures > 0) {
        std::cerr << failures << " release metadata test(s) failed\n";
        return 1;
    }
    std::cout << "All release metadata tests passed\n";
    return 0;
}

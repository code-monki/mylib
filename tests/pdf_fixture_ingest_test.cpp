#include "ingest/pdf_probe.hpp"

#include <iostream>
#include <stdexcept>
#include <string>

namespace {

int failures = 0;

#ifndef MYLIB_REPO_ROOT
#define MYLIB_REPO_ROOT "."
#endif

std::string fixture_path(const std::string& relative) {
    return std::string(MYLIB_REPO_ROOT) + "/" + relative;
}

void expect(bool condition, const std::string& message) {
    if (!condition) {
        ++failures;
        std::cerr << "FAIL: " << message << '\n';
    }
}

std::vector<std::uint8_t> must_read(const std::string& path) {
    try {
        return mylib::ingest::read_file_bytes(path);
    } catch (const std::exception& ex) {
        ++failures;
        std::cerr << "FAIL: could not read fixture " << path << " (" << ex.what() << ")\n";
        return {};
    }
}

void test_duplicate_fingerprint() {
    const auto normal = must_read(fixture_path("tests/fixtures/pdfs/normal.pdf"));
    const auto duplicate = must_read(fixture_path("tests/fixtures/pdfs/duplicate.pdf"));
    const auto cursed = must_read(fixture_path("tests/fixtures/pdfs/cursed.pdf"));

    expect(!normal.empty(), "normal.pdf should be readable");
    expect(!duplicate.empty(), "duplicate.pdf should be readable");
    expect(!cursed.empty(), "cursed.pdf should be readable");

    const auto normal_fp = mylib::ingest::fingerprint_hex_fnv1a64(normal);
    const auto duplicate_fp = mylib::ingest::fingerprint_hex_fnv1a64(duplicate);
    const auto cursed_fp = mylib::ingest::fingerprint_hex_fnv1a64(cursed);

    expect(normal_fp == duplicate_fp, "duplicate fixture should match normal fingerprint");
    expect(normal_fp != cursed_fp, "cursed fixture should not match normal fingerprint");
}

void test_fixture_signals() {
    const auto normal = must_read(fixture_path("tests/fixtures/pdfs/normal.pdf"));
    const auto duplicate = must_read(fixture_path("tests/fixtures/pdfs/duplicate.pdf"));
    const auto cursed = must_read(fixture_path("tests/fixtures/pdfs/cursed.pdf"));

    if (normal.empty() || duplicate.empty() || cursed.empty()) {
        return;
    }

    const auto normal_signals = mylib::ingest::probe_pdf_signals(normal);
    const auto duplicate_signals = mylib::ingest::probe_pdf_signals(duplicate);
    const auto cursed_signals = mylib::ingest::probe_pdf_signals(cursed);

    expect(
        normal_signals.byte_size == duplicate_signals.byte_size,
        "normal and duplicate should have the same byte size"
    );
    expect(
        normal_signals.image_marker_count == duplicate_signals.image_marker_count,
        "normal and duplicate should have the same image marker count"
    );
    expect(
        normal_signals.text_operator_count == duplicate_signals.text_operator_count,
        "normal and duplicate should have the same text operator count"
    );

    expect(
        cursed_signals.byte_size > normal_signals.byte_size,
        "cursed fixture should be larger than normal fixture"
    );
    expect(
        !cursed_signals.has_title_metadata,
        "cursed fixture should not expose title metadata marker"
    );
}

}  // namespace

int main() {
    test_duplicate_fingerprint();
    test_fixture_signals();

    if (failures > 0) {
        std::cerr << failures << " fixture ingest test(s) failed\n";
        return 1;
    }

    std::cout << "All PDF fixture ingest tests passed\n";
    return 0;
}

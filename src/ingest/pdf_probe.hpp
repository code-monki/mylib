#pragma once

#include <cstddef>
#include <cstdint>
#include <string>
#include <vector>

namespace mylib::ingest {

struct PdfSignals {
    std::size_t byte_size = 0;
    std::size_t text_operator_count = 0;
    std::size_t image_marker_count = 0;
    bool has_title_metadata = false;
};

std::vector<std::uint8_t> read_file_bytes(const std::string& path);
std::string fingerprint_hex_fnv1a64(const std::vector<std::uint8_t>& bytes);
PdfSignals probe_pdf_signals(const std::vector<std::uint8_t>& bytes);

}  // namespace mylib::ingest

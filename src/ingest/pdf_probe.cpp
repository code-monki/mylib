#include "ingest/pdf_probe.hpp"

#include <fstream>
#include <iomanip>
#include <sstream>
#include <stdexcept>

namespace mylib::ingest {

namespace {

std::size_t count_marker(
    const std::vector<std::uint8_t>& bytes,
    const std::string& marker
) {
    if (bytes.empty() || marker.empty()) {
        return 0;
    }

    std::size_t count = 0;
    for (std::size_t i = 0; i + marker.size() <= bytes.size(); ++i) {
        bool match = true;
        for (std::size_t j = 0; j < marker.size(); ++j) {
            if (bytes[i + j] != static_cast<std::uint8_t>(marker[j])) {
                match = false;
                break;
            }
        }
        if (match) {
            ++count;
        }
    }
    return count;
}

}  // namespace

std::vector<std::uint8_t> read_file_bytes(const std::string& path) {
    std::ifstream input(path, std::ios::binary);
    if (!input) {
        throw std::runtime_error("unable to open file: " + path);
    }

    return std::vector<std::uint8_t>(
        std::istreambuf_iterator<char>(input),
        std::istreambuf_iterator<char>()
    );
}

std::string fingerprint_hex_fnv1a64(const std::vector<std::uint8_t>& bytes) {
    std::uint64_t hash = 14695981039346656037ull;
    constexpr std::uint64_t prime = 1099511628211ull;

    for (const auto byte : bytes) {
        hash ^= static_cast<std::uint64_t>(byte);
        hash *= prime;
    }

    std::ostringstream out;
    out << std::hex << std::setfill('0') << std::setw(16) << hash;
    return out.str();
}

PdfSignals probe_pdf_signals(const std::vector<std::uint8_t>& bytes) {
    PdfSignals signals{};
    signals.byte_size = bytes.size();
    signals.text_operator_count = count_marker(bytes, "Tj") + count_marker(bytes, "TJ");
    signals.image_marker_count = count_marker(bytes, "/Image") + count_marker(bytes, "/XObject");
    signals.has_title_metadata = count_marker(bytes, "/Title") > 0;
    return signals;
}

}  // namespace mylib::ingest

#pragma once

#include "search/query_service.hpp"

#include <cstddef>
#include <string>
#include <vector>

namespace mylib::perf {

struct QueryLatencyProbe {
    std::size_t iterations = 0;
    double average_ms = 0.0;
    double p95_ms = 0.0;
    std::size_t result_count_checksum = 0;
};

struct MemoryEstimate {
    std::size_t record_count = 0;
    std::size_t estimated_bytes = 0;
};

QueryLatencyProbe run_query_latency_probe(
    mylib::search::QueryService& query_service,
    const std::string& query,
    std::size_t iterations
);

MemoryEstimate estimate_catalog_memory(const std::vector<mylib::domain::CatalogRecord>& records);

}  // namespace mylib::perf

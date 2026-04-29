#include "perf/performance_harness.hpp"

#include <algorithm>
#include <chrono>

namespace mylib::perf {

namespace {

double percentile_95(std::vector<double> samples_ms) {
    if (samples_ms.empty()) return 0.0;
    const std::size_t idx = ((samples_ms.size() - 1) * 95) / 100;
    std::nth_element(samples_ms.begin(), samples_ms.begin() + static_cast<long>(idx), samples_ms.end());
    return samples_ms[idx];
}

}  // namespace

QueryLatencyProbe run_query_latency_probe(
    mylib::search::QueryService& query_service,
    const std::string& query,
    std::size_t iterations
) {
    QueryLatencyProbe probe{};
    probe.iterations = iterations;
    if (iterations == 0) return probe;

    std::vector<double> samples_ms;
    samples_ms.reserve(iterations);

    double total_ms = 0.0;
    std::size_t checksum = 0;
    for (std::size_t i = 0; i < iterations; ++i) {
        const auto begin = std::chrono::steady_clock::now();
        const auto result = query_service.execute(query);
        const auto end = std::chrono::steady_clock::now();
        const auto elapsed_ms = std::chrono::duration<double, std::milli>(end - begin).count();
        samples_ms.push_back(elapsed_ms);
        total_ms += elapsed_ms;
        checksum += result.matches.size();
    }

    probe.average_ms = total_ms / static_cast<double>(iterations);
    probe.p95_ms = percentile_95(samples_ms);
    probe.result_count_checksum = checksum;
    return probe;
}

MemoryEstimate estimate_catalog_memory(const std::vector<mylib::domain::CatalogRecord>& records) {
    std::size_t bytes = 0;
    for (const auto& record : records) {
        bytes += sizeof(record);
        bytes += record.id.size();
        bytes += record.title.size();
        bytes += record.source_path.size();
        bytes += record.source_fingerprint.size();
        for (const auto& tag : record.tags) {
            bytes += tag.size();
        }
    }
    return {records.size(), bytes};
}

}  // namespace mylib::perf

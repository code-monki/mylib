#include "perf/performance_harness.hpp"
#include "search/query_service.hpp"
#include "storage/in_memory_catalog_repository.hpp"

#include <iostream>
#include <string>

namespace {

int failures = 0;

void expect(bool condition, const std::string& message) {
    if (!condition) {
        ++failures;
        std::cerr << "FAIL: " << message << '\n';
    }
}

void seed_scale_fixture(mylib::storage::InMemoryCatalogRepository& repo, std::size_t record_count) {
    for (std::size_t i = 0; i < record_count; ++i) {
        const bool hot = (i % 10 == 0);
        repo.create(mylib::domain::CatalogRecord{
            .id = "perf-" + std::to_string(i),
            .title = hot ? "Hot Query Title " + std::to_string(i) : "Library Item " + std::to_string(i),
            .tags = {hot ? "tag-hot" : "tag-cold", "batch"},
            .source_path = "/tmp/perf-" + std::to_string(i) + ".pdf",
            .source_fingerprint = "perfhash" + std::to_string(i) + "abcd",
            .version = 1,
        });
    }
}

void test_performance_harness_probe() {
    mylib::storage::InMemoryCatalogRepository repo;
    seed_scale_fixture(repo, 1200);
    mylib::search::QueryService search(repo);

    const auto probe = mylib::perf::run_query_latency_probe(search, "tag-hot OR title", 200);
    expect(probe.iterations == 200, "latency probe should record iteration count");
    expect(probe.result_count_checksum > 0, "latency probe should return non-empty matches over iterations");
    expect(probe.average_ms < 20.0, "average query latency should remain under threshold");
    expect(probe.p95_ms < 40.0, "p95 query latency should remain under threshold");

    const auto memory = mylib::perf::estimate_catalog_memory(repo.list_all());
    expect(memory.record_count == 1200, "memory estimate should include all seeded records");
    expect(memory.estimated_bytes > 1200 * 60, "memory estimate should exceed minimal per-record floor");
}

}  // namespace

int main() {
    test_performance_harness_probe();
    if (failures > 0) {
        std::cerr << failures << " performance harness test(s) failed\n";
        return 1;
    }
    std::cout << "All performance harness tests passed\n";
    return 0;
}

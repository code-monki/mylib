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

void seed(mylib::storage::InMemoryCatalogRepository& repo) {
    repo.create(mylib::domain::CatalogRecord{
        .id = "s-1",
        .title = "Distributed Systems Notes",
        .tags = {"systems", "distributed"},
        .source_path = "/tmp/s1.pdf",
        .source_fingerprint = "11111111aaaaaaa1",
        .version = 1,
    });
    repo.create(mylib::domain::CatalogRecord{
        .id = "s-2",
        .title = "Security Operations Guide",
        .tags = {"security", "ops"},
        .source_path = "/tmp/s2.pdf",
        .source_fingerprint = "22222222bbbbbbb2",
        .version = 1,
    });
}

void test_query_grammar() {
    mylib::storage::InMemoryCatalogRepository repo;
    seed(repo);
    mylib::search::QueryService search(repo);

    auto q1 = search.execute("security OR distributed");
    expect(q1.status == mylib::search::QueryStatus::ok, "or query should parse");
    expect(q1.matches.size() == 2, "or query should match both records");

    auto q2 = search.execute("security AND NOT distributed");
    expect(q2.status == mylib::search::QueryStatus::ok, "and/not query should parse");
    expect(q2.matches.size() == 1, "and/not query should match one record");
    expect(q2.matches[0].id == "s-2", "and/not query should match security record");

    auto bad = search.execute("(security AND distributed");
    expect(bad.status == mylib::search::QueryStatus::invalid_query, "unbalanced query should fail");
}

void test_rebuild_admin_gate() {
    mylib::storage::InMemoryCatalogRepository repo;
    mylib::search::QueryService search(repo);

    auto denied = search.trigger_rebuild(false, "online");
    expect(denied.status == mylib::search::RebuildStatus::forbidden, "non-admin rebuild must be denied");

    auto invalid = search.trigger_rebuild(true, "invalid-mode");
    expect(
        invalid.status == mylib::search::RebuildStatus::invalid_mode,
        "invalid rebuild mode must be rejected"
    );

    auto accepted = search.trigger_rebuild(true, "maintenance");
    expect(accepted.status == mylib::search::RebuildStatus::accepted, "admin rebuild should be accepted");
    expect(
        search.rebuild_state() == mylib::search::RebuildState::completed,
        "rebuild should end in completed state"
    );
}
}  // namespace

int main() {
    test_query_grammar();
    test_rebuild_admin_gate();

    if (failures > 0) {
        std::cerr << failures << " search query test(s) failed\n";
        return 1;
    }
    std::cout << "All search query tests passed\n";
    return 0;
}

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

void test_create_and_read() {
    mylib::storage::InMemoryCatalogRepository repo;
    const mylib::domain::CatalogRecord seed{
        .id = "bk-001",
        .title = "Normal PDF Reference",
        .tags = {"reference", "seed"},
        .version = 1,
    };

    const auto created = repo.create(seed);
    expect(created.status == mylib::storage::SaveStatus::ok, "create should succeed");
    expect(created.record.has_value(), "create should return persisted record");
    expect(created.record->version == 1, "new record should start at version 1");

    const auto loaded = repo.get_by_id("bk-001");
    expect(loaded.has_value(), "created record should be loadable");
    expect(loaded->title == "Normal PDF Reference", "title should round-trip");
}

void test_validation_and_duplicate_rejection() {
    mylib::storage::InMemoryCatalogRepository repo;

    const mylib::domain::CatalogRecord invalid{
        .id = "bad-001",
        .title = "   ",
        .tags = {"ok"},
        .version = 1,
    };

    const auto invalid_result = repo.create(invalid);
    expect(
        invalid_result.status == mylib::storage::SaveStatus::validation_failed,
        "invalid record should be rejected"
    );

    const mylib::domain::CatalogRecord valid{
        .id = "dup-001",
        .title = "Duplicate Candidate",
        .tags = {"import"},
        .version = 1,
    };
    expect(
        repo.create(valid).status == mylib::storage::SaveStatus::ok,
        "first create should succeed"
    );
    expect(
        repo.create(valid).status == mylib::storage::SaveStatus::already_exists,
        "second create should be duplicate"
    );
}

void test_optimistic_concurrency_update() {
    mylib::storage::InMemoryCatalogRepository repo;
    const mylib::domain::CatalogRecord base{
        .id = "occ-001",
        .title = "Versioned Record",
        .tags = {"v1"},
        .version = 1,
    };
    const auto created = repo.create(base);
    expect(created.status == mylib::storage::SaveStatus::ok, "seed create should succeed");

    mylib::domain::CatalogRecord update_v2{
        .id = "occ-001",
        .title = "Versioned Record Updated",
        .tags = {"v2"},
        .version = 1,
    };
    const auto updated = repo.update(update_v2, 1);
    expect(updated.status == mylib::storage::SaveStatus::ok, "update with correct version should succeed");
    expect(updated.record.has_value(), "successful update should return record");
    expect(updated.record->version == 2, "version should increment");

    mylib::domain::CatalogRecord stale_update{
        .id = "occ-001",
        .title = "Stale Writer Attempt",
        .tags = {"stale"},
        .version = 1,
    };
    const auto conflict = repo.update(stale_update, 1);
    expect(
        conflict.status == mylib::storage::SaveStatus::version_conflict,
        "stale expected version should conflict"
    );
}

}  // namespace

int main() {
    test_create_and_read();
    test_validation_and_duplicate_rejection();
    test_optimistic_concurrency_update();

    if (failures > 0) {
        std::cerr << failures << " catalog contract test(s) failed\n";
        return 1;
    }

    std::cout << "All catalog contract tests passed\n";
    return 0;
}

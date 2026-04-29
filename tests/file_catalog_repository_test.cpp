#include "storage/file_catalog_repository.hpp"

#include <filesystem>
#include <iostream>
#include <string>
#include <vector>

namespace {
int failures = 0;
void expect(bool cond, const std::string& msg) {
    if (!cond) {
        ++failures;
        std::cerr << "FAIL: " << msg << '\n';
    }
}

std::string temp_db_path(const std::string& name) {
    return (std::filesystem::temp_directory_path() / name).string();
}

void test_roundtrip_persistence() {
    const auto db = temp_db_path("mylib-file-repo-test.db");
    std::filesystem::remove(db);

    {
        mylib::storage::FileCatalogRepository repo(db);
        const mylib::domain::CatalogRecord rec{
            .id = "f-001",
            .title = "File backed record",
            .tags = {"persist", "catalog"},
            .source_path = "/tmp/file.pdf",
            .source_fingerprint = "abcdef1234567890",
            .version = 1,
        };
        const auto created = repo.create(rec);
        expect(created.status == mylib::storage::SaveStatus::ok, "file repo create should succeed");
    }

    {
        mylib::storage::FileCatalogRepository repo(db);
        const auto loaded = repo.get_by_id("f-001");
        expect(loaded.has_value(), "record should reload from disk");
        if (loaded) {
            expect(loaded->title == "File backed record", "title should persist");
            expect(loaded->tags.size() == 2, "tags should persist");
            expect(loaded->version == 1, "version should persist");
        }
    }
    std::filesystem::remove(db);
}

void test_update_and_delete() {
    const auto db = temp_db_path("mylib-file-repo-update-test.db");
    std::filesystem::remove(db);

    mylib::storage::FileCatalogRepository repo(db);
    const mylib::domain::CatalogRecord rec{
        .id = "f-002",
        .title = "Versioned",
        .tags = {"v1"},
        .source_path = "/tmp/v1.pdf",
        .source_fingerprint = "ffff111122223333",
        .version = 1,
    };
    expect(repo.create(rec).status == mylib::storage::SaveStatus::ok, "seed create should succeed");

    auto updated = rec;
    updated.title = "Versioned 2";
    updated.tags = {"v2"};
    const auto save = repo.update(updated, 1);
    expect(save.status == mylib::storage::SaveStatus::ok, "update with expected version should succeed");
    expect(save.record->version == 2, "version should increment to 2");

    const auto deleted = repo.delete_by_id("f-002");
    expect(deleted.status == mylib::storage::DeleteStatus::deleted, "delete should succeed");
    expect(!repo.get_by_id("f-002").has_value(), "deleted record should be absent");
    std::filesystem::remove(db);
}

void test_io_error_create_is_retry_safe_and_hooked() {
    const auto db = temp_db_path("mylib-file-repo-io-fail.db");
    std::filesystem::remove(db);
    std::vector<std::string> hook_events;
    mylib::storage::FileCatalogRepository repo(
        db,
        [&hook_events](const std::string& action, const std::string& detail) {
            hook_events.push_back(action + ":" + detail);
        },
        true
    );

    const mylib::domain::CatalogRecord rec{
        .id = "f-003",
        .title = "Persisted",
        .tags = {"tag"},
        .source_path = "/tmp/p.pdf",
        .source_fingerprint = "ff00aa11",
        .version = 1,
    };
    const auto create_result = repo.create(rec);
    expect(create_result.status == mylib::storage::SaveStatus::io_error, "create should surface io_error");
    expect(!repo.get_by_id("f-003").has_value(), "failed create should not mutate in-memory state");
    expect(hook_events.size() >= 1, "io error hook should be invoked for failed write operations");
    std::filesystem::remove(db);
}
}  // namespace

int main() {
    test_roundtrip_persistence();
    test_update_and_delete();
    test_io_error_create_is_retry_safe_and_hooked();
    if (failures > 0) {
        std::cerr << failures << " file repository test(s) failed\n";
        return 1;
    }
    std::cout << "All file repository tests passed\n";
    return 0;
}

#include "storage/in_memory_catalog_repository.hpp"
#include "storage/storage_mediation_service.hpp"

#include <filesystem>
#include <fstream>
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

#ifndef MYLIB_REPO_ROOT
#define MYLIB_REPO_ROOT "."
#endif

std::string fixture_path(const std::string& relative) {
    return std::string(MYLIB_REPO_ROOT) + "/" + relative;
}

std::string write_tmp_file(const std::string& name, const std::string& content) {
    const auto path = std::filesystem::temp_directory_path() / name;
    std::ofstream out(path, std::ios::binary);
    out << content;
    return path.string();
}

void test_open_request_and_relink() {
    mylib::storage::InMemoryCatalogRepository repo;
    mylib::storage::StorageMediationService storage(repo);

    mylib::domain::CatalogRecord record{
        .id = "st-001",
        .title = "Storage mediation test",
        .tags = {"storage"},
        .source_path = fixture_path("tests/fixtures/pdfs/normal.pdf"),
        .source_fingerprint = "abc12345deadbeef",
        .version = 1,
    };
    expect(repo.create(record).status == mylib::storage::SaveStatus::ok, "seed record create should work");

    const auto open = storage.build_open_request("st-001", "Preview");
    expect(open.status == mylib::storage::ReaderOpenStatus::ready, "open request should be ready");
    expect(!open.file_path.empty(), "open request should include path");

    auto relink_target = write_tmp_file("mylib-relink-target.pdf", "placeholder");
    auto relink_status = storage.relink_record("st-001", relink_target);
    expect(relink_status == mylib::storage::RelinkStatus::relinked, "relink should succeed for existing target");

    const auto relinked_open = storage.build_open_request("st-001", "Preview");
    expect(relinked_open.file_path == relink_target, "open request should resolve relinked path");

    std::filesystem::remove(relink_target);
}

void test_remove_policies() {
    mylib::storage::InMemoryCatalogRepository repo;
    mylib::storage::StorageMediationService storage(repo);

    const auto keep_path = write_tmp_file("mylib-keep-file.pdf", "keep me");
    mylib::domain::CatalogRecord keep_record{
        .id = "st-002",
        .title = "Catalog only remove",
        .tags = {"remove"},
        .source_path = keep_path,
        .source_fingerprint = "bbbbbbbbcccccccc",
        .version = 1,
    };
    expect(repo.create(keep_record).status == mylib::storage::SaveStatus::ok, "keep record create should work");

    const auto keep_result = storage.remove_record("st-002", mylib::storage::RemovalMode::catalog_only);
    expect(
        keep_result.status == mylib::storage::RemovalStatus::removed_catalog_only,
        "catalog-only removal should remove record and keep file"
    );
    expect(std::filesystem::exists(keep_path), "catalog-only mode should not delete file");
    std::filesystem::remove(keep_path);

    const auto delete_path = write_tmp_file("mylib-delete-file.pdf", "delete me");
    mylib::domain::CatalogRecord delete_record{
        .id = "st-003",
        .title = "Delete on disk remove",
        .tags = {"remove"},
        .source_path = delete_path,
        .source_fingerprint = "ddddddddeeeeeeee",
        .version = 1,
    };
    expect(repo.create(delete_record).status == mylib::storage::SaveStatus::ok, "delete record create should work");

    const auto delete_result = storage.remove_record("st-003", mylib::storage::RemovalMode::delete_from_disk);
    expect(
        delete_result.status == mylib::storage::RemovalStatus::removed_and_file_deleted,
        "delete mode should remove catalog record and file"
    );
    expect(!std::filesystem::exists(delete_path), "delete mode should remove file from disk");
}

}  // namespace

int main() {
    test_open_request_and_relink();
    test_remove_policies();

    if (failures > 0) {
        std::cerr << failures << " storage mediation test(s) failed\n";
        return 1;
    }

    std::cout << "All storage mediation tests passed\n";
    return 0;
}

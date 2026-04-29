#include "config/bootstrap.hpp"
#include "storage/file_catalog_repository.hpp"
#include "storage/in_memory_catalog_repository.hpp"
#include "storage/repository_factory.hpp"

#include <filesystem>
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

void test_in_memory_selection() {
    mylib::config::RuntimeConfig cfg{};
    cfg.repository_backend = "in_memory";
    cfg.repository_file.clear();

    auto repo = mylib::storage::create_repository(cfg);
    const bool is_expected = dynamic_cast<mylib::storage::InMemoryCatalogRepository*>(repo.get()) != nullptr;
    expect(is_expected, "in_memory backend should create InMemoryCatalogRepository");
}

void test_file_selection_creates_parent_dir() {
    const auto root = std::filesystem::temp_directory_path() / "mylib-repository-factory-test";
    const auto db = root / "nested" / "catalog.db";
    std::filesystem::remove_all(root);

    mylib::config::RuntimeConfig cfg{};
    cfg.repository_backend = "file";
    cfg.repository_file = db.string();

    auto repo = mylib::storage::create_repository(cfg);
    const bool is_expected = dynamic_cast<mylib::storage::FileCatalogRepository*>(repo.get()) != nullptr;
    expect(is_expected, "file backend should create FileCatalogRepository");
    expect(std::filesystem::exists(db.parent_path()), "file backend should create parent directory");

    std::filesystem::remove_all(root);
}

}  // namespace

int main() {
    test_in_memory_selection();
    test_file_selection_creates_parent_dir();

    if (failures > 0) {
        std::cerr << failures << " repository factory test(s) failed\n";
        return 1;
    }
    std::cout << "All repository factory tests passed\n";
    return 0;
}

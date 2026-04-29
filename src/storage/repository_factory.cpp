#include "storage/repository_factory.hpp"

#include "storage/file_catalog_repository.hpp"
#include "storage/in_memory_catalog_repository.hpp"

#include <filesystem>

namespace mylib::storage {

std::unique_ptr<CatalogRepository> create_repository(const mylib::config::RuntimeConfig& cfg) {
    if (cfg.repository_backend == "file" && !cfg.repository_file.empty()) {
        std::filesystem::path file_path(cfg.repository_file);
        if (file_path.has_parent_path()) {
            std::filesystem::create_directories(file_path.parent_path());
        }
        return std::make_unique<FileCatalogRepository>(file_path.string());
    }
    return std::make_unique<InMemoryCatalogRepository>();
}

}  // namespace mylib::storage

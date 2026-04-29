#pragma once

#include "config/bootstrap.hpp"
#include "storage/catalog_repository.hpp"

#include <memory>

namespace mylib::storage {

std::unique_ptr<CatalogRepository> create_repository(const mylib::config::RuntimeConfig& cfg);

}  // namespace mylib::storage

#include "config/bootstrap.hpp"
#include "storage/repository_factory.hpp"

#include <iostream>

int main() {
    const auto cfg = mylib::config::load_config_from_env();
    auto repository = mylib::storage::create_repository(cfg);
    std::cout << "[mylib] runtime bootstrap: " << mylib::config::describe(cfg) << '\n';
    std::cout << "[mylib] repository bootstrapped with "
              << repository->list_all().size()
              << " records\n";
    return 0;
}

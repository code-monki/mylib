#include "config/bootstrap.hpp"

#include <iostream>

int main() {
    const auto cfg = mylib::config::load_config_from_env();
    std::cout << "[mylib] runtime bootstrap: " << mylib::config::describe(cfg) << '\n';
    return 0;
}

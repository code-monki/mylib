#pragma once

#include <string>

namespace mylib::config {

struct RuntimeConfig {
    std::string environment = "dev";
    int api_port = 8080;
    bool enable_structured_logs = true;
    std::string repository_backend = "in_memory";
    std::string repository_file;
};

RuntimeConfig load_config_from_env();
std::string describe(const RuntimeConfig& cfg);

}  // namespace mylib::config

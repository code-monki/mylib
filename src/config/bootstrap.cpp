#include "config/bootstrap.hpp"

#include <cstdlib>
#include <sstream>

namespace mylib::config {

namespace {

int parse_port(const char* value, int fallback) {
    if (value == nullptr) {
        return fallback;
    }

    char* end = nullptr;
    const long parsed = std::strtol(value, &end, 10);
    if (end == value || *end != '\0') {
        return fallback;
    }

    if (parsed < 1 || parsed > 65535) {
        return fallback;
    }
    return static_cast<int>(parsed);
}

bool parse_bool(const char* value, bool fallback) {
    if (value == nullptr) {
        return fallback;
    }
    const std::string candidate(value);
    if (candidate == "1" || candidate == "true" || candidate == "TRUE") {
        return true;
    }
    if (candidate == "0" || candidate == "false" || candidate == "FALSE") {
        return false;
    }
    return fallback;
}

}  // namespace

RuntimeConfig load_config_from_env() {
    RuntimeConfig cfg{};

    if (const char* env = std::getenv("MYLIB_ENV"); env != nullptr && *env != '\0') {
        cfg.environment = env;
    }

    cfg.api_port = parse_port(std::getenv("MYLIB_API_PORT"), cfg.api_port);
    cfg.enable_structured_logs = parse_bool(
        std::getenv("MYLIB_ENABLE_STRUCTURED_LOGS"),
        cfg.enable_structured_logs
    );

    return cfg;
}

std::string describe(const RuntimeConfig& cfg) {
    std::ostringstream oss;
    oss << "environment=" << cfg.environment
        << ", api_port=" << cfg.api_port
        << ", structured_logs=" << (cfg.enable_structured_logs ? "on" : "off");
    return oss.str();
}

}  // namespace mylib::config

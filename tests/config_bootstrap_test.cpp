#include "config/bootstrap.hpp"

#include <cstdlib>
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

void clear_env(const char* key) {
#if defined(_WIN32)
    _putenv_s(key, "");
#else
    unsetenv(key);
#endif
}

void set_env(const char* key, const char* value) {
#if defined(_WIN32)
    _putenv_s(key, value);
#else
    setenv(key, value, 1);
#endif
}

void test_defaults() {
    clear_env("MYLIB_ENV");
    clear_env("MYLIB_API_PORT");
    clear_env("MYLIB_ENABLE_STRUCTURED_LOGS");

    const auto cfg = mylib::config::load_config_from_env();
    expect(cfg.environment == "dev", "default environment should be dev");
    expect(cfg.api_port == 8080, "default port should be 8080");
    expect(cfg.enable_structured_logs, "default structured logs should be enabled");
}

void test_overrides() {
    set_env("MYLIB_ENV", "test");
    set_env("MYLIB_API_PORT", "9000");
    set_env("MYLIB_ENABLE_STRUCTURED_LOGS", "false");

    const auto cfg = mylib::config::load_config_from_env();
    expect(cfg.environment == "test", "environment should honor override");
    expect(cfg.api_port == 9000, "port should honor numeric override");
    expect(!cfg.enable_structured_logs, "structured log flag should parse false");
}

void test_invalid_fallbacks() {
    set_env("MYLIB_API_PORT", "not-a-number");
    set_env("MYLIB_ENABLE_STRUCTURED_LOGS", "not-a-bool");

    const auto cfg = mylib::config::load_config_from_env();
    expect(cfg.api_port == 8080, "invalid port should fall back to default");
    expect(cfg.enable_structured_logs, "invalid bool should fall back to default");
}

}  // namespace

int main() {
    test_defaults();
    test_overrides();
    test_invalid_fallbacks();

    if (failures > 0) {
        std::cerr << failures << " test(s) failed\n";
        return 1;
    }

    std::cout << "All config bootstrap tests passed\n";
    return 0;
}

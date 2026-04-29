#include "security/auth_service.hpp"

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

void test_bootstrap_and_auth() {
    mylib::security::AuthService auth;
    expect(auth.bootstrap_admin("admin", "secret"), "bootstrap admin should succeed once");
    expect(!auth.bootstrap_admin("admin2", "secret2"), "second bootstrap should fail");
    expect(auth.user_count() == 1, "user count should remain one after bootstrap");

    auto bad = auth.authenticate("admin", "wrong");
    expect(!bad.has_value(), "wrong password should fail");

    auto good = auth.authenticate("admin", "secret");
    expect(good.has_value(), "correct credentials should authenticate");
    expect(
        auth.authorize(good->token, mylib::security::Role::admin, "default"),
        "admin session should authorize admin role in tenant"
    );
}

void test_tenant_and_role_boundaries() {
    mylib::security::AuthService auth;
    expect(auth.bootstrap_admin("admin", "secret"), "bootstrap should succeed");
    expect(auth.create_user("alice", "pw1", mylib::security::Role::user, "tenant-a"), "create alice");

    auto alice = auth.authenticate("alice", "pw1");
    expect(alice.has_value(), "alice should authenticate");
    expect(
        !auth.authorize(alice->token, mylib::security::Role::admin, "tenant-a"),
        "user role should not authorize admin operation"
    );
    expect(
        !auth.authorize(alice->token, mylib::security::Role::user, "tenant-b"),
        "wrong tenant should be denied"
    );
}
}  // namespace

int main() {
    test_bootstrap_and_auth();
    test_tenant_and_role_boundaries();
    if (failures > 0) {
        std::cerr << failures << " auth service test(s) failed\n";
        return 1;
    }
    std::cout << "All auth service tests passed\n";
    return 0;
}

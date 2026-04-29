#pragma once

#include <optional>
#include <string>
#include <unordered_map>
#include <vector>

namespace mylib::security {

enum class Role {
    user,
    admin,
};

struct Session {
    std::string token;
    std::string username;
    Role role = Role::user;
    std::string tenant = "default";
};

class AuthService {
public:
    bool bootstrap_admin(const std::string& username, const std::string& password);
    bool create_user(
        const std::string& username,
        const std::string& password,
        Role role,
        const std::string& tenant
    );

    std::optional<Session> authenticate(const std::string& username, const std::string& password);
    bool authorize(const std::string& token, Role minimum_role, const std::string& tenant) const;
    std::size_t user_count() const;

private:
    struct User {
        std::string username;
        std::string password_hash;
        Role role = Role::user;
        std::string tenant = "default";
    };

    std::unordered_map<std::string, User> users_;
    std::unordered_map<std::string, Session> sessions_;
    std::size_t next_token_ = 1;
};

}  // namespace mylib::security

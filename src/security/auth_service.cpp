#include "security/auth_service.hpp"

#include <sstream>

namespace mylib::security {

namespace {

std::string pseudo_hash(const std::string& password) {
    std::ostringstream out;
    out << "hash::" << password;
    return out.str();
}

bool role_allows(Role held, Role required) {
    if (required == Role::user) return true;
    return held == Role::admin;
}

}  // namespace

bool AuthService::bootstrap_admin(const std::string& username, const std::string& password) {
    if (!users_.empty() || username.empty() || password.empty()) {
        return false;
    }
    users_[username] = User{
        .username = username,
        .password_hash = pseudo_hash(password),
        .role = Role::admin,
        .tenant = "default",
    };
    return true;
}

bool AuthService::create_user(
    const std::string& username,
    const std::string& password,
    Role role,
    const std::string& tenant
) {
    if (username.empty() || password.empty() || tenant.empty() || users_.contains(username)) {
        return false;
    }
    users_[username] = User{
        .username = username,
        .password_hash = pseudo_hash(password),
        .role = role,
        .tenant = tenant,
    };
    return true;
}

std::optional<Session> AuthService::authenticate(
    const std::string& username,
    const std::string& password
) {
    const auto it = users_.find(username);
    if (it == users_.end()) {
        return std::nullopt;
    }
    if (it->second.password_hash != pseudo_hash(password)) {
        return std::nullopt;
    }

    Session session{
        .token = "session-" + std::to_string(next_token_++),
        .username = it->second.username,
        .role = it->second.role,
        .tenant = it->second.tenant,
    };
    sessions_[session.token] = session;
    return session;
}

bool AuthService::authorize(const std::string& token, Role minimum_role, const std::string& tenant) const {
    const auto it = sessions_.find(token);
    if (it == sessions_.end()) {
        return false;
    }
    if (!role_allows(it->second.role, minimum_role)) {
        return false;
    }
    return it->second.tenant == tenant;
}

std::size_t AuthService::user_count() const { return users_.size(); }

}  // namespace mylib::security

#include "observability/audit_observability_service.hpp"

#include <algorithm>

namespace mylib::observability {

namespace {

std::string redact_token(std::string value, const std::string& key) {
    std::string marker = key + "=";
    auto pos = value.find(marker);
    while (pos != std::string::npos) {
        auto end = value.find(' ', pos);
        value.replace(pos + marker.size(), (end == std::string::npos ? value.size() : end) - (pos + marker.size()), "<redacted>");
        pos = value.find(marker, pos + marker.size());
    }
    return value;
}

}  // namespace

std::string AuditObservabilityService::sanitize_detail(const std::string& detail) {
    auto sanitized = detail;
    sanitized = redact_token(sanitized, "password");
    sanitized = redact_token(sanitized, "token");
    sanitized = redact_token(sanitized, "secret");
    return sanitized;
}

void AuditObservabilityService::record_audit(
    const std::string& action,
    const std::string& actor,
    const std::string& tenant,
    const std::string& detail
) {
    events_.push_back(Event{
        .event_class = EventClass::audit,
        .action = action,
        .actor = actor,
        .tenant = tenant,
        .detail = sanitize_detail(detail),
    });
}

void AuditObservabilityService::record_ops(
    const std::string& action,
    const std::string& tenant,
    const std::string& detail
) {
    events_.push_back(Event{
        .event_class = EventClass::ops,
        .action = action,
        .actor = "system",
        .tenant = tenant,
        .detail = sanitize_detail(detail),
    });
}

std::vector<Event> AuditObservabilityService::audit_events() const {
    std::vector<Event> out;
    for (const auto& e : events_) {
        if (e.event_class == EventClass::audit) out.push_back(e);
    }
    return out;
}

std::vector<Event> AuditObservabilityService::ops_events() const {
    std::vector<Event> out;
    for (const auto& e : events_) {
        if (e.event_class == EventClass::ops) out.push_back(e);
    }
    return out;
}

}  // namespace mylib::observability

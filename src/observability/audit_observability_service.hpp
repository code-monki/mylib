#pragma once

#include <string>
#include <vector>

namespace mylib::observability {

enum class EventClass {
    audit,
    ops,
};

struct Event {
    EventClass event_class = EventClass::ops;
    std::string action;
    std::string actor;
    std::string tenant;
    std::string detail;
};

class AuditObservabilityService {
public:
    void record_audit(
        const std::string& action,
        const std::string& actor,
        const std::string& tenant,
        const std::string& detail
    );
    void record_ops(
        const std::string& action,
        const std::string& tenant,
        const std::string& detail
    );

    std::vector<Event> audit_events() const;
    std::vector<Event> ops_events() const;

private:
    static std::string sanitize_detail(const std::string& detail);

    std::vector<Event> events_;
};

}  // namespace mylib::observability

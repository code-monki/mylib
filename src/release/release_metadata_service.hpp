#pragma once

#include <string>
#include <vector>

namespace mylib::release {

struct ReleaseMetadata {
    std::string version;
    std::string build_id;
    std::vector<std::string> required_artifacts;
};

struct PackagingCheck {
    bool ok = false;
    std::vector<std::string> missing;
};

class ReleaseMetadataService {
public:
    ReleaseMetadata metadata() const;
    PackagingCheck verify_required_artifacts(const std::string& repo_root) const;
};

}  // namespace mylib::release

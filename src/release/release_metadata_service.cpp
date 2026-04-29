#include "release/release_metadata_service.hpp"

#include <filesystem>

namespace mylib::release {

ReleaseMetadata ReleaseMetadataService::metadata() const {
    return ReleaseMetadata{
        .version = "0.1.0",
        .build_id = "mylib-dev-build",
        .required_artifacts = {"LICENSE", "NOTICE"},
    };
}

PackagingCheck ReleaseMetadataService::verify_required_artifacts(const std::string& repo_root) const {
    const auto meta = metadata();
    PackagingCheck check{};
    for (const auto& file : meta.required_artifacts) {
        if (!std::filesystem::exists(std::filesystem::path(repo_root) / file)) {
            check.missing.push_back(file);
        }
    }
    check.ok = check.missing.empty();
    return check;
}

}  // namespace mylib::release

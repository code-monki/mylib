#include "release/release_metadata_service.hpp"

#include <cstdlib>
#include <filesystem>
#include <fstream>
#include <sstream>

namespace mylib::release {

ReleaseMetadata ReleaseMetadataService::metadata() const {
    return ReleaseMetadata{
        .version = "0.1.0",
        .build_id = "mylib-dev-build",
        .required_artifacts = {"LICENSE", "NOTICE", "OPERATIONS-ROLLBACK-RUNBOOK.md"},
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

RollbackDrillEvidence ReleaseMetadataService::run_rollback_drill(const std::string& repo_root) const {
    RollbackDrillEvidence evidence{};
    std::ostringstream report;

    const auto packaging = verify_required_artifacts(repo_root);
    if (packaging.ok) {
        evidence.completed_steps.push_back("preflight-artifacts");
    } else {
        evidence.failed_steps.push_back("preflight-artifacts");
        report << "missing artifacts:";
        for (const auto& missing : packaging.missing) report << " " << missing;
        report << '\n';
    }

    const auto temp_snapshot = std::filesystem::temp_directory_path() / ("mylib-rollback-drill-" + metadata().version);
    {
        std::ofstream out(temp_snapshot, std::ios::trunc);
        if (!out) {
            evidence.failed_steps.push_back("backup-snapshot-write");
        } else {
            out << "version=" << metadata().version << "\n";
            out << "build_id=" << metadata().build_id << "\n";
            evidence.completed_steps.push_back("backup-snapshot-write");
        }
    }

    {
        std::ifstream in(temp_snapshot);
        std::string contents((std::istreambuf_iterator<char>(in)), std::istreambuf_iterator<char>());
        if (!in || contents.find("version=" + metadata().version) == std::string::npos) {
            evidence.failed_steps.push_back("restore-readback");
        } else {
            evidence.completed_steps.push_back("restore-readback");
        }
    }

    std::error_code ec;
    std::filesystem::remove(temp_snapshot, ec);
    if (ec) {
        evidence.failed_steps.push_back("cleanup-snapshot");
        report << "snapshot cleanup failed: " << ec.message() << '\n';
    } else {
        evidence.completed_steps.push_back("cleanup-snapshot");
    }

    evidence.ok = evidence.failed_steps.empty();
    if (evidence.ok) {
        report << "rollback drill passed with " << evidence.completed_steps.size() << " completed steps";
    }
    evidence.report = report.str();
    return evidence;
}

}  // namespace mylib::release

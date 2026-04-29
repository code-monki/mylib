#include "storage/file_catalog_repository.hpp"

#include "domain/catalog_record.hpp"

#include <algorithm>
#include <fstream>
#include <optional>
#include <sstream>

namespace mylib::storage {

namespace {

std::vector<std::string> split(const std::string& line, char delim) {
    std::vector<std::string> parts;
    std::string current;
    std::stringstream ss(line);
    while (std::getline(ss, current, delim)) {
        parts.push_back(current);
    }
    return parts;
}

std::string join_tags(const std::vector<std::string>& tags) {
    std::ostringstream out;
    for (std::size_t i = 0; i < tags.size(); ++i) {
        if (i > 0) out << ",";
        out << tags[i];
    }
    return out.str();
}

std::vector<std::string> split_tags(const std::string& tags) {
    if (tags.empty()) return {};
    return split(tags, ',');
}

}  // namespace

FileCatalogRepository::FileCatalogRepository(
    std::string storage_file,
    IoErrorHook io_error_hook,
    bool force_persist_failure_for_test
)
    : storage_file_(std::move(storage_file)),
      io_error_hook_(std::move(io_error_hook)),
      force_persist_failure_for_test_(force_persist_failure_for_test) {
    load_from_disk();
}

SaveResult FileCatalogRepository::create(const mylib::domain::CatalogRecord& record) {
    const auto normalized = mylib::domain::normalize_catalog_record(record);
    if (!normalized.has_value()) return {SaveStatus::validation_failed, std::nullopt};
    if (records_.contains(normalized->id)) return {SaveStatus::already_exists, std::nullopt};

    auto persisted = *normalized;
    persisted.version = 1;
    auto next_records = records_;
    next_records[persisted.id] = persisted;
    if (!flush_to_disk(next_records)) {
        emit_io_error("create", "unable to persist record id=" + persisted.id);
        return {SaveStatus::io_error, std::nullopt};
    }
    records_ = std::move(next_records);
    return {SaveStatus::ok, persisted};
}

std::optional<mylib::domain::CatalogRecord> FileCatalogRepository::get_by_id(const std::string& id) const {
    const auto it = records_.find(id);
    if (it == records_.end()) return std::nullopt;
    return it->second;
}

SaveResult FileCatalogRepository::update(
    const mylib::domain::CatalogRecord& updated_record,
    int expected_version
) {
    const auto normalized = mylib::domain::normalize_catalog_record(updated_record);
    if (!normalized.has_value()) return {SaveStatus::validation_failed, std::nullopt};

    const auto it = records_.find(normalized->id);
    if (it == records_.end()) return {SaveStatus::not_found, std::nullopt};
    if (it->second.version != expected_version) return {SaveStatus::version_conflict, it->second};

    auto persisted = *normalized;
    persisted.version = it->second.version + 1;
    auto next_records = records_;
    next_records[persisted.id] = persisted;
    if (!flush_to_disk(next_records)) {
        emit_io_error("update", "unable to persist record id=" + persisted.id);
        return {SaveStatus::io_error, it->second};
    }
    records_ = std::move(next_records);
    return {SaveStatus::ok, persisted};
}

DeleteResult FileCatalogRepository::delete_by_id(const std::string& id) {
    const auto it = records_.find(id);
    if (it == records_.end()) return {DeleteStatus::not_found, std::nullopt};
    auto deleted = it->second;
    auto next_records = records_;
    next_records.erase(id);
    if (!flush_to_disk(next_records)) {
        emit_io_error("delete", "unable to persist delete id=" + id);
        return {DeleteStatus::io_error, deleted};
    }
    records_ = std::move(next_records);
    return {DeleteStatus::deleted, deleted};
}

std::vector<mylib::domain::CatalogRecord> FileCatalogRepository::list_all() const {
    std::vector<mylib::domain::CatalogRecord> out;
    out.reserve(records_.size());
    for (const auto& [_, rec] : records_) out.push_back(rec);
    return out;
}

bool FileCatalogRepository::load_from_disk() {
    std::ifstream in(storage_file_);
    if (!in) return true;
    std::unordered_map<std::string, mylib::domain::CatalogRecord> loaded_records;
    std::string line;
    while (std::getline(in, line)) {
        if (line.empty()) continue;
        const auto parts = split(line, '|');
        if (parts.size() != 6) {
            emit_io_error("load", "invalid line while loading catalog store");
            continue;
        }

        mylib::domain::CatalogRecord rec{};
        rec.id = decode_field(parts[0]);
        rec.title = decode_field(parts[1]);
        rec.source_path = decode_field(parts[2]);
        rec.source_fingerprint = decode_field(parts[3]);
        rec.tags = split_tags(decode_field(parts[4]));
        try {
            rec.version = std::max(1, std::stoi(parts[5]));
        } catch (...) {
            emit_io_error("load", "invalid version while loading catalog store");
            continue;
        }
        loaded_records[rec.id] = rec;
    }
    records_ = std::move(loaded_records);
    return true;
}

bool FileCatalogRepository::flush_to_disk(
    const std::unordered_map<std::string, mylib::domain::CatalogRecord>& records
) const {
    if (force_persist_failure_for_test_) return false;

    std::ofstream out(storage_file_, std::ios::trunc);
    if (!out) return false;

    for (const auto& [_, rec] : records) {
        out << encode_field(rec.id) << "|"
            << encode_field(rec.title) << "|"
            << encode_field(rec.source_path) << "|"
            << encode_field(rec.source_fingerprint) << "|"
            << encode_field(join_tags(rec.tags)) << "|"
            << rec.version << "\n";
    }
    out.flush();
    return out.good();
}

void FileCatalogRepository::emit_io_error(const std::string& action, const std::string& detail) const {
    if (io_error_hook_) {
        io_error_hook_(action, detail);
    }
}

std::string FileCatalogRepository::encode_field(const std::string& value) {
    std::string out;
    out.reserve(value.size());
    for (char c : value) {
        if (c == '\\' || c == '|') out.push_back('\\');
        out.push_back(c);
    }
    return out;
}

std::string FileCatalogRepository::decode_field(const std::string& value) {
    std::string out;
    out.reserve(value.size());
    bool escaped = false;
    for (char c : value) {
        if (escaped) {
            out.push_back(c);
            escaped = false;
            continue;
        }
        if (c == '\\') {
            escaped = true;
            continue;
        }
        out.push_back(c);
    }
    return out;
}

}  // namespace mylib::storage

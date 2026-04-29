#include "ingest/import_service.hpp"
#include "storage/in_memory_catalog_repository.hpp"

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

#ifndef MYLIB_REPO_ROOT
#define MYLIB_REPO_ROOT "."
#endif

std::string fixture_path(const std::string& relative) {
    return std::string(MYLIB_REPO_ROOT) + "/" + relative;
}

void test_duplicate_requires_explicit_decision() {
    mylib::storage::InMemoryCatalogRepository repo;
    mylib::ingest::ImportService service(repo);

    const auto draft_normal = service.create_draft("imp-001", fixture_path("tests/fixtures/pdfs/normal.pdf"));
    expect(draft_normal.has_value(), "normal draft should be created");
    auto first = service.commit_draft(*draft_normal, true, false);
    expect(first.status == mylib::ingest::ImportCommitStatus::imported, "first import should succeed");

    const auto draft_duplicate =
        service.create_draft("imp-002", fixture_path("tests/fixtures/pdfs/duplicate.pdf"));
    expect(draft_duplicate.has_value(), "duplicate draft should be created");
    expect(draft_duplicate->duplicate_of_id.has_value(), "duplicate record should be detected in draft");

    auto blocked = service.commit_draft(*draft_duplicate, false, false);
    expect(
        blocked.status == mylib::ingest::ImportCommitStatus::duplicate_requires_decision,
        "duplicate commit should block without explicit decision"
    );
}

void test_metadata_hints_are_user_gated() {
    mylib::storage::InMemoryCatalogRepository repo;
    mylib::ingest::ImportService service(repo);

    const auto draft = service.create_draft("imp-003", fixture_path("tests/fixtures/pdfs/normal.pdf"));
    expect(draft.has_value(), "draft should be created");
    expect(!draft->hints.empty(), "draft should include metadata hints");

    auto no_hint = service.commit_draft(*draft, true, false);
    expect(no_hint.status == mylib::ingest::ImportCommitStatus::imported, "import without hints should succeed");
    expect(no_hint.record->title == "Untitled import", "title should remain default when hint is not applied");

    const auto draft_with_hint = service.create_draft("imp-004", fixture_path("tests/fixtures/pdfs/cursed.pdf"));
    auto with_hint = service.commit_draft(*draft_with_hint, true, true);
    expect(with_hint.status == mylib::ingest::ImportCommitStatus::imported, "import with hints should succeed");
    expect(with_hint.record->title == "cursed", "title should use filename hint when explicitly applied");
}

}  // namespace

int main() {
    test_duplicate_requires_explicit_decision();
    test_metadata_hints_are_user_gated();

    if (failures > 0) {
        std::cerr << failures << " import service test(s) failed\n";
        return 1;
    }

    std::cout << "All import service tests passed\n";
    return 0;
}

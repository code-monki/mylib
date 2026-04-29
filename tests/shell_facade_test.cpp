#include "ingest/import_service.hpp"
#include "search/query_service.hpp"
#include "security/auth_service.hpp"
#include "shell/shell_facade.hpp"
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

void test_shell_flow() {
    mylib::storage::InMemoryCatalogRepository repo;
    mylib::search::QueryService search(repo);
    mylib::security::AuthService auth;
    mylib::ingest::ImportService ingest(repo);
    mylib::shell::ShellFacade shell(auth, search, ingest, repo);

    expect(auth.bootstrap_admin("admin", "secret"), "admin bootstrap should succeed");

    const auto session = shell.login("admin", "secret");
    expect(session.has_value(), "login should return session");

    const auto draft = shell.start_import("sh-001", fixture_path("tests/fixtures/pdfs/normal.pdf"));
    expect(draft.has_value(), "shell import draft should be created");
    auto imported = ingest.commit_draft(*draft, true, true);
    expect(
        imported.status == mylib::ingest::ImportCommitStatus::imported,
        "draft commit should import successfully"
    );

    const auto library = shell.library();
    expect(!library.empty(), "library should list imported record");

    const auto results = shell.search_library("normal OR untitled");
    expect(results.status == mylib::search::QueryStatus::ok, "shell search should succeed");
    expect(!results.matches.empty(), "shell search should return imported record");

    auto rebuild = shell.run_admin_rebuild(session->token, "online");
    expect(rebuild.status == mylib::search::RebuildStatus::accepted, "admin rebuild should succeed");
}
}  // namespace

int main() {
    test_shell_flow();
    if (failures > 0) {
        std::cerr << failures << " shell facade test(s) failed\n";
        return 1;
    }
    std::cout << "All shell facade tests passed\n";
    return 0;
}

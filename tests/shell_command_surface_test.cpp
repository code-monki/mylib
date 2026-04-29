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

void test_command_scenarios() {
    mylib::storage::InMemoryCatalogRepository repo;
    mylib::search::QueryService search(repo);
    mylib::security::AuthService auth;
    mylib::ingest::ImportService ingest(repo);
    mylib::shell::ShellFacade shell(auth, search, ingest, repo);

    expect(auth.bootstrap_admin("admin", "secret"), "admin bootstrap should succeed");

    const auto empty = shell.execute_command("");
    expect(empty.status == mylib::shell::ShellCommandStatus::invalid_command, "empty command should be rejected");

    const auto help = shell.execute_command("help");
    expect(help.status == mylib::shell::ShellCommandStatus::ok, "help should succeed");

    const auto bad_login = shell.execute_command("login admin");
    expect(
        bad_login.status == mylib::shell::ShellCommandStatus::invalid_arguments,
        "invalid login arguments should fail"
    );

    const auto login = shell.execute_command("login admin secret");
    expect(login.status == mylib::shell::ShellCommandStatus::ok, "login command should succeed");

    const auto no_draft_commit = shell.execute_command("import-commit true true");
    expect(
        no_draft_commit.status == mylib::shell::ShellCommandStatus::failed,
        "commit without draft should fail"
    );

    const auto draft = shell.execute_command(
        "import-draft s-001 " + fixture_path("tests/fixtures/pdfs/normal.pdf")
    );
    expect(draft.status == mylib::shell::ShellCommandStatus::ok, "draft command should succeed");

    const auto bad_bool = shell.execute_command("import-commit maybe true");
    expect(
        bad_bool.status == mylib::shell::ShellCommandStatus::invalid_arguments,
        "invalid bool argument should fail"
    );

    const auto commit = shell.execute_command("import-commit true true");
    expect(commit.status == mylib::shell::ShellCommandStatus::ok, "commit command should succeed");

    const auto search_ok = shell.execute_command("search normal OR untitled");
    expect(search_ok.status == mylib::shell::ShellCommandStatus::ok, "search command should succeed");
    expect(search_ok.result_count > 0, "search should return imported record");

    const auto search_invalid = shell.execute_command("search )");
    expect(search_invalid.status == mylib::shell::ShellCommandStatus::failed, "invalid query should fail");

    const auto rebuild = shell.execute_command("rebuild online");
    expect(rebuild.status == mylib::shell::ShellCommandStatus::ok, "rebuild command should succeed for admin");

    const auto unknown = shell.execute_command("does-not-exist");
    expect(
        unknown.status == mylib::shell::ShellCommandStatus::invalid_command,
        "unknown command should be rejected"
    );
}

}  // namespace

int main() {
    test_command_scenarios();
    if (failures > 0) {
        std::cerr << failures << " shell command surface test(s) failed\n";
        return 1;
    }
    std::cout << "All shell command surface tests passed\n";
    return 0;
}

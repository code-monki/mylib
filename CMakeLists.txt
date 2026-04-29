cmake_minimum_required(VERSION 3.20)

project(mylib VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

option(MYLIB_WARNINGS_AS_ERRORS "Treat compiler warnings as errors" OFF)

add_library(mylib_core
    src/observability/audit_observability_service.cpp
    src/quality/test_evidence_service.cpp
    src/release/release_metadata_service.cpp
    src/config/bootstrap.cpp
    src/domain/catalog_record.cpp
    src/ingest/import_service.cpp
    src/ingest/metadata_providers.cpp
    src/ingest/pdf_probe.cpp
    src/ocr/ocr_boundary_service.cpp
    src/perf/performance_harness.cpp
    src/search/query_service.cpp
    src/security/auth_service.cpp
    src/shell/shell_facade.cpp
    src/storage/in_memory_catalog_repository.cpp
    src/storage/file_catalog_repository.cpp
    src/storage/repository_factory.cpp
    src/storage/storage_mediation_service.cpp
)

target_include_directories(mylib_core
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)

if(MSVC)
    target_compile_options(mylib_core PRIVATE /W4)
    if(MYLIB_WARNINGS_AS_ERRORS)
        target_compile_options(mylib_core PRIVATE /WX)
    endif()
else()
    target_compile_options(mylib_core PRIVATE -Wall -Wextra -Wpedantic)
    if(MYLIB_WARNINGS_AS_ERRORS)
        target_compile_options(mylib_core PRIVATE -Werror)
    endif()
endif()

add_executable(mylib_app src/main.cpp)
target_link_libraries(mylib_app PRIVATE mylib_core)

enable_testing()
add_executable(config_bootstrap_test tests/config_bootstrap_test.cpp)
target_link_libraries(config_bootstrap_test PRIVATE mylib_core)
add_test(NAME config_bootstrap_test COMMAND config_bootstrap_test)

add_executable(pdf_fixture_ingest_test tests/pdf_fixture_ingest_test.cpp)
target_link_libraries(pdf_fixture_ingest_test PRIVATE mylib_core)
target_compile_definitions(
    pdf_fixture_ingest_test
    PRIVATE
        MYLIB_REPO_ROOT="${CMAKE_CURRENT_SOURCE_DIR}"
)
add_test(NAME pdf_fixture_ingest_test COMMAND pdf_fixture_ingest_test)

add_executable(catalog_contract_test tests/catalog_contract_test.cpp)
target_link_libraries(catalog_contract_test PRIVATE mylib_core)
add_test(NAME catalog_contract_test COMMAND catalog_contract_test)

add_executable(import_service_test tests/import_service_test.cpp)
target_link_libraries(import_service_test PRIVATE mylib_core)
target_compile_definitions(
    import_service_test
    PRIVATE
        MYLIB_REPO_ROOT="${CMAKE_CURRENT_SOURCE_DIR}"
)
add_test(NAME import_service_test COMMAND import_service_test)

add_executable(storage_mediation_service_test tests/storage_mediation_service_test.cpp)
target_link_libraries(storage_mediation_service_test PRIVATE mylib_core)
target_compile_definitions(
    storage_mediation_service_test
    PRIVATE
        MYLIB_REPO_ROOT="${CMAKE_CURRENT_SOURCE_DIR}"
)
add_test(NAME storage_mediation_service_test COMMAND storage_mediation_service_test)

add_executable(search_query_service_test tests/search_query_service_test.cpp)
target_link_libraries(search_query_service_test PRIVATE mylib_core)
add_test(NAME search_query_service_test COMMAND search_query_service_test)

add_executable(ocr_boundary_service_test tests/ocr_boundary_service_test.cpp)
target_link_libraries(ocr_boundary_service_test PRIVATE mylib_core)
target_compile_definitions(
    ocr_boundary_service_test
    PRIVATE
        MYLIB_REPO_ROOT="${CMAKE_CURRENT_SOURCE_DIR}"
)
add_test(NAME ocr_boundary_service_test COMMAND ocr_boundary_service_test)

add_executable(security_auth_service_test tests/security_auth_service_test.cpp)
target_link_libraries(security_auth_service_test PRIVATE mylib_core)
add_test(NAME security_auth_service_test COMMAND security_auth_service_test)

add_executable(shell_facade_test tests/shell_facade_test.cpp)
target_link_libraries(shell_facade_test PRIVATE mylib_core)
target_compile_definitions(
    shell_facade_test
    PRIVATE
        MYLIB_REPO_ROOT="${CMAKE_CURRENT_SOURCE_DIR}"
)
add_test(NAME shell_facade_test COMMAND shell_facade_test)

add_executable(shell_command_surface_test tests/shell_command_surface_test.cpp)
target_link_libraries(shell_command_surface_test PRIVATE mylib_core)
target_compile_definitions(
    shell_command_surface_test
    PRIVATE
        MYLIB_REPO_ROOT="${CMAKE_CURRENT_SOURCE_DIR}"
)
add_test(NAME shell_command_surface_test COMMAND shell_command_surface_test)

add_executable(audit_observability_service_test tests/audit_observability_service_test.cpp)
target_link_libraries(audit_observability_service_test PRIVATE mylib_core)
add_test(NAME audit_observability_service_test COMMAND audit_observability_service_test)

add_executable(test_evidence_service_test tests/test_evidence_service_test.cpp)
target_link_libraries(test_evidence_service_test PRIVATE mylib_core)
add_test(NAME test_evidence_service_test COMMAND test_evidence_service_test)

add_executable(release_metadata_service_test tests/release_metadata_service_test.cpp)
target_link_libraries(release_metadata_service_test PRIVATE mylib_core)
target_compile_definitions(
    release_metadata_service_test
    PRIVATE
        MYLIB_REPO_ROOT="${CMAKE_CURRENT_SOURCE_DIR}"
)
add_test(NAME release_metadata_service_test COMMAND release_metadata_service_test)

add_executable(file_catalog_repository_test tests/file_catalog_repository_test.cpp)
target_link_libraries(file_catalog_repository_test PRIVATE mylib_core)
add_test(NAME file_catalog_repository_test COMMAND file_catalog_repository_test)

add_executable(repository_factory_test tests/repository_factory_test.cpp)
target_link_libraries(repository_factory_test PRIVATE mylib_core)
add_test(NAME repository_factory_test COMMAND repository_factory_test)

add_executable(performance_scale_harness_test tests/performance_scale_harness_test.cpp)
target_link_libraries(performance_scale_harness_test PRIVATE mylib_core)
add_test(NAME performance_scale_harness_test COMMAND performance_scale_harness_test)

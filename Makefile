SHELL := /bin/sh

# Top-level build/test orchestrator for MyLib.
# Always invoke project workflows through this Makefile.

CMAKE ?= cmake
CTEST ?= ctest
PYTHON ?= python3
BUILD_DIR ?= build
BUILD_TYPE ?= Debug
CONFIG_STAMP := $(BUILD_DIR)/.configured
CONFIG_INPUTS := CMakeLists.txt

.PHONY: help configure build test run complexity verify clean distclean
.DEFAULT_GOAL := help

help:
	@echo "Targets:"
	@echo "  configure  - Configure CMake project into $(BUILD_DIR)"
	@echo "  build      - Build all targets"
	@echo "  test       - Run test suite (ctest)"
	@echo "  run        - Run mylib_app"
	@echo "  complexity - Run cyclomatic complexity scan (lizard)"
	@echo "  verify     - Run test suite + complexity scan"
	@echo "  clean      - Remove compiled outputs and configure stamp"
	@echo "  distclean  - Remove entire $(BUILD_DIR) directory"

$(CONFIG_STAMP): $(CONFIG_INPUTS)
	@mkdir -p $(BUILD_DIR)
	$(CMAKE) -S . -B $(BUILD_DIR) -DCMAKE_BUILD_TYPE=$(BUILD_TYPE)
	@touch $(CONFIG_STAMP)

configure: $(CONFIG_STAMP)

build: $(CONFIG_STAMP)
	$(CMAKE) --build $(BUILD_DIR)

test: build
	$(CTEST) --test-dir $(BUILD_DIR) --output-on-failure

run: build
	./$(BUILD_DIR)/mylib_app

complexity:
	$(PYTHON) -m lizard src tests

verify: test complexity

clean:
	@if [ -d "$(BUILD_DIR)" ]; then $(CMAKE) --build $(BUILD_DIR) --target clean; rm -f "$(CONFIG_STAMP)"; else echo "No $(BUILD_DIR) directory"; fi

distclean:
	rm -rf $(BUILD_DIR)

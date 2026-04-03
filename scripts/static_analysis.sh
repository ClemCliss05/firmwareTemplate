#!/bin/bash
set -e

./scripts/format.sh
./scripts/clang-tidy.sh
./scripts/cppcheck.sh
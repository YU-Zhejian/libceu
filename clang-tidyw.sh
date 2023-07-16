#!/usr/bin/env bash
# Shell script that counts how many lines of code was written by us.
# shellcheck disable=SC2086
git ls-files |
        grep -v 'deps' |
        grep -v '.idea/' |
        while read -r line; do
          if [ -e "${line}" ]; then
          clang-format -style=.clang-tidy "${line}"
           fi
            done
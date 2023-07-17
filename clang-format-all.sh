#!/usr/bin/env bash
# Shell script that counts how many lines of code was written by us.
# shellcheck disable=SC2086
git ls-files |
    grep -v 'deps' |
    grep -v '.idea/' |
    grep -e '\.cc$' -e '\.cpp$' -e '\.c$' -e '\.h$' -e '\.hpp$' |
    while read -r line; do
        if [ -e "${line}" ]; then
            echo "${line}"
            ./clang-formatw.sh "${line}" &
        fi
    done
wait

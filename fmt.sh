#!/usr/bin/env bash
# Shell script that counts how many lines of code was written by us.
# shellcheck disable=SC2086
git ls-files |
    while read -r line; do
        if [ -e "${line}" ]; then
            {
                echo DOS2UNIX "${line}"
                dos2unix "${line}"
            } &
        fi
    done
wait

git ls-files |
    grep -v 'deps' |
    grep -v '.idea/' |
    grep '\.sh$' |
    while read -r line; do
        if [ -e "${line}" ]; then
            {
                echo SHFMT "${line}"
                shfmt -i 4 --write "${line}"
            } &
        fi
    done
wait

git ls-files |
    grep -v 'deps' |
    grep -v '.idea/' |
    grep -e '\.py$' -e '\.pyi$' |
    while read -r line; do
        if [ -e "${line}" ]; then
            {
                echo BLACK "${line}"
                black --line-length 120 --target-version py38 --quiet "${line}"
            } &
        fi
    done
wait

git ls-files |
    grep -v 'deps' |
    grep -v '.idea/' |
    grep -e '\.cc$' -e '\.cpp$' -e '\.c$' -e '\.h$' -e '\.hh' -e '\.hpp$' |
    while read -r line; do
        if [ -e "${line}" ]; then
            {
                echo "CLANG-FORMAT ${line}"
                ./clang-formatw.sh "${line}"
            } &
        fi
    done
wait

git ls-files |
    grep -v 'deps' |
    grep -v '.idea/' |
    grep -e '\.cmake$' -e 'CMakeLists.txt' |
    while read -r line; do
        if [ -e "${line}" ]; then
            {
                echo "CMAKE-FORMAT ${line}"
                cmake-format \
                    --tab-size 4 \
                    --line-width 120 \
                    --use-tabchars false \
                    --in-place "${line}"
            } &
        fi
    done
wait

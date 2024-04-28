#!/usr/bin/env bash
find . | while read -r line; do
    echo "${line}"
    touch "${line}"
done

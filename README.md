# Advent of Code 2024 (C++)

Trying out C++23 with Bazel on Advent of Code 2024!

## Requirements
- C++23
- Bazel

## Build
`bazel build //...`

## Test
All - `bazel test //...`
Specific Day - `bazel test main/{DAY}:test`

## Run
Specific Day - `bazel run main/{DAY}:main -- main/{DAY}/input.txt`
load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library", "cc_test")

cc_library(
    name = "solution",
    srcs = ["solution.cpp"],
    hdrs = ["solution.h"],
    deps = ["//lib:input"],
)

cc_test(
    name = "test",
    srcs = ["test.cpp"],
    copts = [
        "-Iexternal/gtest/googletest/include",
        "-Iexternal/gtest/googletest",
    ],
    deps = [
        ":solution",
        "@googletest//:gtest",
        "@googletest//:gtest_main",
    ],
)

cc_binary(
    name = "main",
    srcs = ["main.cpp"],
    data = [
        ":input_file",
    ],
    deps = [
        ":solution",
        "//lib:input",
    ],
)

filegroup(
    name = "input_file",
    srcs = ["input.txt"],
)

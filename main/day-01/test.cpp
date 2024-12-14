#include <gtest/gtest.h>

#include "solution.h"

TEST(SolutionTest, PartOneExample) {
    // auto input = R"(
    // 8999
    // 9000
    // 9001
    // )";

    std::vector<std::string> lines;

    lines.emplace_back("8999");

    constexpr int expected = 9001;
    const int actual = solution_part_one(lines);

    EXPECT_EQ(actual, expected);
}

#include <gtest/gtest.h>

#include "solution.h"
#include "lib/input.h"

TEST(SolutionTest, PartOneExample) {
    const auto input = R"(
    8999
    9000
    9001
    )";

    const auto lines = clean_input(input);

    constexpr long expected = 0;
    const long actual = solution_part_one(lines);

    EXPECT_EQ(actual, expected);
}

TEST(SolutionTest, PartTwoExample) {
    const auto input = R"(
    8999
    9000
    9001
    )";

    const auto lines = clean_input(input);

    constexpr long expected = 0;
    const long actual = solution_part_two(lines);

    EXPECT_EQ(actual, expected);
}
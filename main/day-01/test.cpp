#include <gtest/gtest.h>

#include "solution.h"
#include "lib/input.h"

TEST(SolutionTest, PartOneExample) {
    const auto input = R"(
    3   4
    4   3
    2   5
    1   3
    3   9
    3   3
    )";

    const auto lines = clean_input(input);

    constexpr long expected = 11;
    const long actual = solution_part_one(lines);

    EXPECT_EQ(actual, expected);
}

TEST(SolutionTest, PartTwoExample) {
    const auto input = R"(
    3   4
    4   3
    2   5
    1   3
    3   9
    3   3
    )";

    const auto lines = clean_input(input);

    constexpr long expected = 0;
    const long actual = solution_part_two(lines);

    EXPECT_EQ(actual, expected);
}

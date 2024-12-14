#include <gtest/gtest.h>

#include "solution.h"
#include "lib/input.h"

TEST(SolutionTest, PartOneExample) {
    const auto input = R"(
    7 6 4 2 1
    1 2 7 8 9
    9 7 6 2 1
    1 3 2 4 5
    8 6 4 4 1
    1 3 6 7 9
    )";

    const auto lines = clean_input(input);

    constexpr long expected = 0;
    const long actual = solution_part_one(lines);

    EXPECT_EQ(actual, expected);
}

TEST(SolutionTest, PartTwoExample) {
    const auto input = R"(
    7 6 4 2 1
    1 2 7 8 9
    9 7 6 2 1
    1 3 2 4 5
    8 6 4 4 1
    1 3 6 7 9
    )";

    const auto lines = clean_input(input);

    constexpr long expected = 0;
    const long actual = solution_part_two(lines);

    EXPECT_EQ(actual, expected);
}
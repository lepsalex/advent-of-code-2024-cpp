#include <gtest/gtest.h>

#include "solution.h"
#include "lib/input.h"

TEST(SolutionTest, PartOneExample) {
    const auto input = R"(
    xmul(2,4)%&mul[3,7]!@^do_not_mul(5,5)+mul(32,64]then(mul(11,8)mul(8,5))
    )";

    const auto lines = clean_input(input);

    constexpr long expected = 161;
    const long actual = solution_part_one(lines);

    EXPECT_EQ(actual, expected);
}

TEST(SolutionTest, PartTwoExample) {
    const auto input = R"(
    xmul(2,4)&mul[3,7]!^don't()_mul(5,5)+mul(32,64](mul(11,8)undo()?mul(8,5))
    )";

    const auto lines = clean_input(input);

    constexpr long expected = 0;
    const long actual = solution_part_two(lines);

    EXPECT_EQ(actual, expected);
}
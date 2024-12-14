#include "solution.h"

#include <iostream>
#include <ranges>
#include <sstream>

namespace rng = std::ranges;
namespace rv = std::ranges::views;

long solution_part_one(const std::vector<std::string> &input) {
    long sum = 0;

    for (const auto& line: input) {
        auto ss = std::istringstream{line};
        auto numbers = rng::istream_view<int>(ss)
                       | rng::to<std::vector<int> >();

        int direction = 0;
        int value{1};

        for (size_t idx = 0; idx < numbers.size(); idx++) {
            if (idx == 0) continue;

            // evaluate absolute difference
            const int abs_diff = std::abs(numbers[idx] - numbers[idx - 1]);
            if (abs_diff == 0 || abs_diff < 1 || abs_diff > 3) {
                value = 0;
                break;
            }

            // get the diff direction
            const int diff = numbers[idx] - numbers[idx - 1];
            const int diff_direction = diff > 0 ? -1 : 1;

            // the first time it's neutral, update with the direction
            if (direction == 0) {
                direction = diff_direction;
                continue;
            }

            // check that the direction as not changed
            if (diff_direction != direction) {
                value = 0;
                break;
            }
        }

        sum += value;
    }

    return sum;
}


long solution_part_two(const std::vector<std::string> &input) {
    for (const auto &line: input) {
        std::print("{}\n", line);
    }

    return 0;
}

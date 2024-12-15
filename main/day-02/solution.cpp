#include "solution.h"

#include <iostream>
#include <ranges>
#include <sstream>
#include <__algorithm/fold.h>

namespace rng = std::ranges;
namespace rv = std::ranges::views;

struct NumbersResult {
    long value;
    int direction;
    int idx;
};

std::vector<int> get_numbers_vec(const std::string &line);

long evaluate(std::vector<int> numbers, bool retry);

long solution_part_one(const std::vector<std::string> &input) {
    return rng::fold_left(input, 0L, [](const auto total, const auto &line) {
        const auto numbers = get_numbers_vec(line);
        const long result = evaluate(numbers, false);
        return total + result;
    });
}

long solution_part_two(const std::vector<std::string> &input) {
    return rng::fold_left(input, 0L, [](const auto total, const auto &line) {
        const auto numbers = get_numbers_vec(line);
        const long result = evaluate(numbers, true);
        return total + result;
    });
}

long evaluate(std::vector<int> numbers, const bool retry) {
    const auto result = rng::fold_left(numbers, NumbersResult(1, 0, 0),
                                       [&numbers](auto acc, const auto number) {
                                           if (acc.idx == 0 || acc.value == 0) {
                                               acc.idx += 1;
                                               return acc;
                                           }

                                           const auto last_number = numbers[acc.idx - 1];

                                           // evaluate absolute difference
                                           const int abs_diff = std::abs(number - last_number);
                                           if (abs_diff == 0 || abs_diff < 1 || abs_diff > 3) {
                                               acc.value = 0;
                                               return acc;
                                           }

                                           // get the diff direction
                                           const int diff = number - last_number;
                                           const int diff_direction = diff > 0 ? -1 : 1;

                                           // the first time it's neutral, update with the direction
                                           if (acc.direction == 0) {
                                               acc.direction = diff_direction;
                                               acc.idx += 1;
                                               return acc;
                                           }

                                           // check that the direction as not changed
                                           if (acc.direction != diff_direction) {
                                               acc.value = 0;
                                           }

                                           acc.idx += 1;
                                           return acc;
                                       });

    // retry false reports by removing at most one number
    if (result.value == 0 && retry == 1) {
        for (const auto remove_idx: rv::iota(0u, numbers.size())) {
            std::vector<int> numbers_copy = numbers;
            numbers_copy.erase(numbers_copy.begin() + remove_idx);
            const long num_removed_result = evaluate(numbers_copy, false);

            if (num_removed_result == 1) {
                return num_removed_result;
            }
        }
    }

    return result.value;
}

std::vector<int> get_numbers_vec(const std::string &line) {
    auto ss = std::istringstream{line};
    return rng::istream_view<int>(ss)
           | rng::to<std::vector<int> >();
}

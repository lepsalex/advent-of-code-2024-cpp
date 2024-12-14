#include "solution.h"

#include <iostream>
#include <ranges>
#include <sstream>

namespace rng = std::ranges;
namespace rv = std::ranges::views;

std::vector<int> get_numbers_vec(const std::string &line);

long evaluate_dampened_report(const std::vector<int> &numbers, int depth = 0);

long solution_part_one(const std::vector<std::string> &input) {
    long sum = 0;

    for (const auto &line: input) {
        auto numbers = get_numbers_vec(line);

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
    long sum = 0;

    for (const auto &line: input) {
        auto numbers = get_numbers_vec(line);
        const auto line_result = evaluate_dampened_report(numbers, 0);
        sum += line_result;
    }

    return sum;
}

long evaluate_dampened_report(const std::vector<int> &numbers, const int depth) {
    int direction = 0;
    long result{1};

    for (size_t idx = 0; idx < numbers.size(); idx++) {
        if (idx == 0) continue;

        // evaluate absolute difference
        const int abs_diff = std::abs(numbers[idx] - numbers[idx - 1]);
        if (abs_diff == 0 || abs_diff < 1 || abs_diff > 3) {
            result = 0;
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
            result = 0;
            break;
        }
    }

    // retry false reports by removing at most one number (controlled by depth)
    if (result == 0 && depth == 0) {
        for (const auto remove_idx: rv::iota(0u, numbers.size())) {
            std::vector<int> numbers_copy = numbers;
            numbers_copy.erase(numbers_copy.begin() + remove_idx);
            long num_removed_result = evaluate_dampened_report(numbers_copy, 1);

            if (num_removed_result == 1) {
                return num_removed_result;
            }
        }
    }

    return result;
}

std::vector<int> get_numbers_vec(const std::string &line) {
    auto ss = std::istringstream{line};
    return rng::istream_view<int>(ss)
           | rng::to<std::vector<int> >();
}

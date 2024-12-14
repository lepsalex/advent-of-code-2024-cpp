#include "solution.h"

#include <algorithm>
#include <istream>
#include <ranges>

long solution_part_one(const std::vector<std::string> &input) {
    std::vector<long> left;
    std::vector<long> right;
    std::string delimiter = "   "; // Three spaces

    // for each line, get the left/right numbers and put them into the vectors above
    for (const auto &line: input) {
        auto parts = std::views::split(line, std::ranges::subrange(delimiter.begin(), delimiter.end()));

        auto it = parts.begin();

        std::string left_val(std::ranges::begin(*it), std::ranges::end(*it));
        left.push_back(std::stol(left_val));

        std::advance(it, 1);

        std::string right_val(std::ranges::begin(*it), std::ranges::end(*it));
        right.push_back(std::stol(right_val));
    }

    // sort
    std::ranges::sort(left);
    std::ranges::sort(right);

    long difference_sum = 0;

    for (size_t idx = 0; idx < left.size(); idx++) {
        difference_sum += std::labs(left[idx] - right[idx]);
    }

    return difference_sum;
}

long solution_part_two(const std::vector<std::string> &input) {
    for (const auto &line: input) {
        std::print("{}\n", line);
    }

    return 0;
}

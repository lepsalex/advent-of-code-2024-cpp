#include "solution.h"

#include <algorithm>
#include <istream>
#include <map>
#include <ranges>

void parse_to_lists(const std::vector<std::string> &input, std::vector<long> &left_out, std::vector<long> &right_out);

long solution_part_one(const std::vector<std::string> &input) {
    // parse the input into two lists of long
    std::vector<long> left;
    std::vector<long> right;
    parse_to_lists(input, left, right);

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
    // parse the input into two lists of long
    std::vector<long> left;
    std::vector<long> right;
    parse_to_lists(input, left, right);

    // create a map of how often a number occurs in the right list
    std::map<long, int> frequency_map;
    for (auto num: right) {
        if (!frequency_map.contains(num)) {
            frequency_map[num] = 0;
        }

        frequency_map[num]++;
    }

    // calculate the sum by multiplying left numbers by the right's frequency if they exist
    long frequency_sum = 0;
    for (auto num: left) {
        if (!frequency_map.contains(num)) {
            continue;
        }

        frequency_sum += num * frequency_map[num];
    }

    return frequency_sum;
}

void parse_to_lists(const std::vector<std::string> &input, std::vector<long> &left_out, std::vector<long> &right_out) {
    std::string delimiter = "   "; // Three spaces

    // for each line, get the left/right numbers and put them into the vectors above
    for (const auto &line: input) {
        auto parts = std::views::split(line, std::ranges::subrange(delimiter.begin(), delimiter.end()));

        auto it = parts.begin();

        std::string left_val(std::ranges::begin(*it), std::ranges::end(*it));
        left_out.push_back(std::stol(left_val));

        std::advance(it, 1);

        std::string right_val(std::ranges::begin(*it), std::ranges::end(*it));
        right_out.push_back(std::stol(right_val));
    }
}

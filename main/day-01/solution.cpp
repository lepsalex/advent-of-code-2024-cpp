#include "solution.h"

#include <algorithm>
#include <istream>
#include <map>
#include <numeric>
#include <ranges>

namespace rng = std::ranges;
namespace rv = std::ranges::views;

void parse_to_lists(const std::vector<std::string> &input, std::vector<long> &left_out, std::vector<long> &right_out);

long solution_part_one(const std::vector<std::string> &input) {
    // parse the input into two lists of long
    std::vector<long> left;
    std::vector<long> right;
    parse_to_lists(input, left, right);

    // sort
    rng::sort(left);
    rng::sort(right);

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

    const auto frequency_map = std::accumulate(right.begin(), right.end(), std::map<long, int>{},
                                               [](const auto map, const auto num) {
                                                   if (!map.contains(num)) {
                                                       map[num] = 0;
                                                   }

                                                   map[num] += 1;

                                                   return map;
                                               });

    return rng::fold_left(left, 0L, [frequency_map](const auto sum, const auto num) {
        if (frequency_map.contains(num)) {
            return sum + (num * frequency_map.at(num));
        }

        return sum;
    });
}

void parse_to_lists(const std::vector<std::string> &input, std::vector<long> &left_out, std::vector<long> &right_out) {
    std::string delimiter = "   "; // Three spaces

    // for each line, get the left/right numbers and put them into the vectors above
    for (const auto &line: input) {
        auto parts = rv::split(line, rng::subrange(delimiter.begin(), delimiter.end()));

        auto it = parts.begin();

        std::string left_val(rng::begin(*it), rng::end(*it));
        left_out.push_back(std::stol(left_val));

        std::advance(it, 1);

        std::string right_val(rng::begin(*it), rng::end(*it));
        right_out.push_back(std::stol(right_val));
    }
}

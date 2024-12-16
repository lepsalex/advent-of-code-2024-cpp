#include "solution.h"

#include <istream>
#include <numeric>
#include <ranges>
#include <regex>

namespace rng = std::ranges;
namespace rv = std::ranges::views;

std::string get_input_as_string(const std::vector<std::string> &input);

long solution_part_one(const std::vector<std::string> &input) {
    const auto text = get_input_as_string(input);

    const std::regex regex(R"(mul\((\d{1,3}),(\d{1,3})\))");
    std::sregex_iterator start{text.begin(), text.end(), regex};
    const std::sregex_iterator end;

    return std::reduce(start, end, 0, [](const long result, const std::smatch &matches) {
        const long product = std::stol(matches[1].str()) * std::stol(matches[2].str());
        return result + product;
    });
}

long solution_part_two(const std::vector<std::string> &input) {
    const auto text = get_input_as_string(input);

    const std::regex regex(R"(mul\((\d{1,3}),(\d{1,3})\)|don't|do)");
    std::sregex_iterator start{text.begin(), text.end(), regex};
    const std::sregex_iterator end;

    bool is_doing = true;

    return std::accumulate(start, end, 0, [&is_doing](const long result, const std::smatch &matches) {
        if (matches[0] == "don't") {
            is_doing = false;
            return result;
        }

        if (matches[0] == "do") {
            is_doing = true;
            return result;
        }

        if (!is_doing) {
            return result;
        }

        const long product = std::stol(matches[1].str()) * std::stol(matches[2].str());
        return result + product;
    });
}

std::string get_input_as_string(const std::vector<std::string> &input) {
    return input
           | rv::join
           | rng::to<std::string>();
}

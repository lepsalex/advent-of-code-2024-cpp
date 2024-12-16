#include "solution.h"

#include <istream>
#include <numeric>
#include <ranges>
#include <regex>

namespace rng = std::ranges;
namespace rv = std::ranges::views;

long solution_part_one(const std::vector<std::string> &input) {
    const auto text = input
                      | rv::join
                      | rng::to<std::string>();

    const std::regex regex(R"(mul\((\d{1,3}),(\d{1,3})\))");
    std::sregex_iterator start{text.begin(), text.end(), regex};
    const std::sregex_iterator end;

    return std::reduce(start, end, 0, [](const long result, const std::smatch &matches) {
        const long product = std::stol(matches[1].str()) * std::stol(matches[2].str());
        return result + product;
    });
}

long solution_part_two(const std::vector<std::string> &input) {
    for (const auto &line: input) {
        std::print("{}\n", line);
    }

    return 0;
}

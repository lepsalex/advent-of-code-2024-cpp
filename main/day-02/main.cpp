#include "solution.h"

#include <fstream>
#include <string>
#include <iostream>

#include "lib/input.h"

int main(const int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "This program expects one parameter that is the input file to read.\n";
        return 1;
    }

    std::vector<std::string> input_lines;
    if (!get_input_lines(argv[1], input_lines)) {
        std::cerr << "Failed to open file.\n";
        return 1;
    }

    const long one = solution_part_one(input_lines);
    const long two = solution_part_two(input_lines);

    std::print("Part One: {}, Part Two: {}\n", one, two);

    return 0;
}

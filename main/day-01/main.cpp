#include "solution.h"

#include <fstream>
#include <string>
#include <iostream>

#include "lib/input.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "This program expects one parameter that is the input file to read.\n";
        return 1;
    }

    std::vector<std::string> input_lines;
    if (!get_input_lines(argv[1], input_lines)) {
        std::cerr << "Failed to open file.\n";
        return 1;
    }

    const int one = solution_part_one(input_lines);
    const int two = solution_part_two();

    printf("Part One: %d, Part Two: %d\n", one, two);

    return 0;
}

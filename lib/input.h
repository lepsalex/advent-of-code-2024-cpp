#pragma once

#include <fstream>
#include <iostream>
#include <vector>

inline bool get_input_lines(const std::string_view file_path, std::vector<std::string> &out_vec) {
    std::ifstream input(file_path);
    if (!input.is_open()) {
        std::cerr << "Failed to open file.\n";
        return false;
    }

    std::string line;
    while (getline(input, line)) {
        out_vec.push_back(line);
    }

    return true;
}

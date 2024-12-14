#pragma once

#include <algorithm>
#include <fstream>
#include <functional>
#include <iostream>
#include <sstream>
#include <vector>

using Predicate = std::function<int(int)>;

void ltrim(std::string &str, Predicate const &pred = isspace);

void rtrim(std::string &str, Predicate const &pred = isspace);

void trim(std::string &str, Predicate const &pred = isspace);

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

inline std::vector<std::string> clean_input(const std::string &input) {
    std::vector<std::string> result;

    std::stringstream string_stream(input);
    std::string line;

    while (getline(string_stream, line)) {
        trim(line);
        if (!line.empty()) {
            result.push_back(line);
        }
    }

    return result;
}

inline void ltrim(std::string &str, Predicate const &pred) {
    str.erase(str.begin(), std::ranges::find_if_not(str, pred));
}

inline void rtrim(std::string &str, Predicate const &pred) {
    str.erase((std::find_if_not(str.rbegin(), str.rend(), pred)).base(), str.end());
}

inline void trim(std::string &str, Predicate const &pred) {
    ltrim(str, pred);
    rtrim(str, pred);
}

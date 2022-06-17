#include "../headers/huffmans_codes.hpp"
#include <iostream>

Huffmans_codes::Huffmans_codes() {
    file_name = "None";
}

Huffmans_codes::~Huffmans_codes() {
}

Huffmans_codes::Huffmans_codes(std::string &f_name) {
    file_name = f_name;
    for (int i = 0; i < 256; i++)
        symbols_frequency[i] = 0;
    count_symbols_frequency();
}

void Huffmans_codes::count_symbols_frequency() {
    char c = 0;

    std::ifstream in(file_name);
    if (!in.is_open()) {
        std::cout << "Can't open file " << file_name << ".\n";
        return;
    }
    while (in.get(c)){
        symbols_frequency[int(c)] += 1;
    }
    for (auto p : symbols_frequency)
        std::cout << p << " ";
    in.close();
}

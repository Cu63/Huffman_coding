#include "../headers/huffmans_codes.hpp"

Huffmans_codes::Huffmans_codes() {
    file_name = "None";
}

Huffmans_codes::~Huffmans_codes() {
}

Huffmans_codes::Huffmans_codes(std::string &f_name) {
    file_name = f_name;
    symbols_frequency.resize(256);
    for (int i = 0; i < 256; i++) {
        symbols_frequency[i].count = 0;
        symbols_frequency[i].c = char(i);
    }
    count_symbols_frequency();
    create_code_tree();
}

void Huffmans_codes::count_symbols_frequency() {
    char c = 0;

    std::ifstream in(file_name);
    if (!in.is_open()) {
        std::cout << "Can't open file " << file_name << ".\n";
        return;
    }
    while (in.get(c)){
        symbols_frequency[int(c)].count += 1;
    }
    in.close();
}

void Huffmans_codes::create_code_tree() {
    std::sort(symbols_frequency.begin(), symbols_frequency.end(),
            [](const symbol &a, const symbol &b)
            { return a.count > b.count; });

    std::cout << "Sorted\n";
    for (int i = 0; i < 255; i++) {
        symbols_frequency[i].print();
        std::cout << " ";
    }
    std::cout << '\n';
}

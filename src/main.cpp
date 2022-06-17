#include "../headers/huffmans_codes.hpp"

#include <iostream>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        std::cout << "Please, write files names. \n"
            << argv[0] <<  " <file name> ...\n";
        return 0;
    }
    for (int i = 1; i < argc; i++) {
        std::string file_name(argv[i]);
        std::cout << file_name << ":\n";
        Huffmans_codes file(file_name);
    }
    return 0;
}

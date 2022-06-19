#ifndef HUFFMANS_CODES_HPP
#define HUFFMANS_CODES_HPP
#include <string>
#include <cstring>
#include <fstream>
#include <array>
#include <utility>
#include <iostream>

class Huffmans_codes {
    private:
        typedef struct s_symbol {
            int count;
            char c;
            int code;

            void print() {
                std::cout << c << ": " << count;
            };
        } symbol;

        std::string file_name;
        symbol symbols_frequency[256];

    public:
        Huffmans_codes(std::string &f_name);
        Huffmans_codes();
        void create_code_tree();
        void count_symbols_frequency();
        ~Huffmans_codes();
};

#endif

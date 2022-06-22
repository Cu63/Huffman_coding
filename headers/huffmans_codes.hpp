#ifndef HUFFMANS_CODES_HPP
#define HUFFMANS_CODES_HPP
#include <string>
#include <cstring>
#include <fstream>
#include <array>
#include <utility>
#include <iostream>
#include <vector>

class Huffmans_codes {
    private:
        typedef struct s_symbol {
            int count;
            char c;
            int code;

            void print() {
                if (uint(c) > 33)
                    std::cout << "\'" << c << "\': ";
                else
                    std::cout << "\'" << uint(c) << "\': ";
                std::cout << count;
            };

        } symbol;

        typedef struct s_node {
            symbol c;
            struct s_node &left;
            struct s_node &right;
        } node;


        std::string file_name;
        std::vector<symbol> symbols_frequency;

    public:
        Huffmans_codes(std::string &f_name);
        Huffmans_codes();
        void create_code_tree();
        void count_symbols_frequency();
        ~Huffmans_codes();
};

#endif

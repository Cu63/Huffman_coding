#ifndef HUFFMANS_CODES_HPP
#define HUFFMANS_CODES_HPP
#include <string>
#include <cstring>
#include <fstream>
#include <array>

class Huffmans_codes {
    private:
        std::string file_name;
        int symbols_frequency[256];
    public:
        Huffmans_codes(std::string &f_name);
        Huffmans_codes();
        void count_symbols_frequency();
        ~Huffmans_codes();
};

#endif

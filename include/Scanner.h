#pragma once

#include <string>

class Scanner {
    public:
        Scanner( std::string const &, bool );
        ~Scanner();
        char getc( void );

    private:
        bool debug;
        int cc;
        char ch;
        int line;
        std::string source;
        int size;
};


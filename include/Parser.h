#pragma once
#include "Lexer.h"

#include <iostream>

class Parser {
    public:
        Parser( std::string *, bool );
        ~Parser();
        bool run( void );
    private:
        bool debug;
        Lexer* lexer;
        std::string *sourcePtr;
};


#pragma once
#include "Lexer.h"

class Parser {
    public:
        Parser();
        ~Parser();
    private:
        Lexer* lexer;
};


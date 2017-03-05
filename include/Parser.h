#pragma once
#include "Lexer.h"

#include <iostream>

class Parser {
    public:
        Parser( std::string const &, bool );
        ~Parser();
        bool run( void );
    private:
        bool debug;
        Lexer* lexer;
        Token token;

        bool match( TokenType );
        void error( TokenType );
        // ebnf rules
        void ebnf_error( std::string );
        bool program( void );
        bool include( void );
};


#pragma once
#include "Scanner.h"
#include "Token.h"

#include <iostream>

class Lexer {
	public:
		Lexer( std::string const &, bool );
		~Lexer();
        Token getToken( void );

    private:
        bool debug;
        Scanner* scanner;
        char ch;

        void skip( void );
};


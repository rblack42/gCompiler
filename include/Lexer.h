#pragma once
#include "Scanner.h"

#include <iostream>

class Lexer {
	public:
		Lexer( bool );
		~Lexer();
        std::string getToken( void );

    private:
        bool debug;
        Scanner* scanner;
};


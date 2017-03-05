#pragma once
#include "Scanner.h"
#include "Token.h"

#include <iostream>
#include <map>

class Lexer {
	public:
		Lexer( std::string const &, bool );
		~Lexer();
        Token getToken( void );
        std::string displayType( TokenType );
    private:
        bool debug;
        Scanner* scanner;
        char ch;
        std::map<std::string, TokenType> res_table;
        void skip( void );
        void init_res_table( void );
        TokenType search( std::string );
};


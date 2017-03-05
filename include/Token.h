#pragma once
#include "TokenType.h"

#include <iostream>

class Token {
    public:
        Token();
        Token(std::string, TokenType );
        void print( void );
        std::string getString( void );
        TokenType getType( void );
        void setString( std::string );
        void setType( TokenType );

    private:
        std::string token_string;
        TokenType token_type;
};
    

#include "Token.h"
#include "TokenType.h"

#include <iostream>

Token::Token() {
    token_string = "";
    token_type = tok_UNKNOWN;
}

Token::Token( std::string s, TokenType t ) {
    token_string = s;
    token_type = t;
}

std::string Token::getString( void ) {
    return token_string;
}

TokenType Token::getType( void ) {
    return token_type;
}

void Token::setString( std::string str ) {
    token_string = str;
}

void Token::setType( TokenType t ) {
    token_type = t;
}

void Token::print( void ) {
    std::cout << token_string;
}


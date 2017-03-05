#include "Parser.h"
#include "Lexer.h"
#include "Token.h"
#include "TokenType.h"

#include <iostream>

// constructor
Parser::Parser( std::string const & source, bool dbg ) {
    debug = dbg;
    if( debug ) {
        std::cout << "Debug: Parser constructor: " << std::endl;
        std::cout << "\tDebug: " << debug << std::endl;
    }
    lexer = new Lexer( source, debug );
}

// destructor
Parser::~Parser() {
    if( debug ) 
        std::cout << "Debug: Parser destructor: " << std::endl;
    delete lexer;
}

bool Parser::run( void ) {
    Token token;
    while (true ) {
        token = lexer->getToken();
        std::cout << "Token: " << token.getString() << std::endl;
        if( token.getType() == tok_EOF ) break;
    }
    return true;
}

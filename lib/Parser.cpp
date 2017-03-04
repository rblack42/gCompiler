#include "Parser.h"
#include "Lexer.h"

#include <iostream>

// constructor
Parser::Parser( std::string * source, bool dbg ) {
    sourcePtr = source;
    debug = dbg;
    if( debug ) {
        std::cout << "Debug: Parser constructor: " << std::endl;
        std::cout << "\tDebug: " << debug << std::endl;
    }
    lexer = new Lexer( debug );
}

// destructor
Parser::~Parser() {
    if( debug ) 
        std::cout << "Debug: Parser destructor: " << std::endl;
    lexer = new Lexer( debug );
    delete lexer;
}

bool Parser::run( void ) {
    std::string token;
    while (true ) {
        token = lexer->getToken();
        if( token == "EOF" ) break;
    }
    return true;
}

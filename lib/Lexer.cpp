#include "Lexer.h"
#include "Scanner.h"

#include <iostream>

// constructor
Lexer::Lexer( bool dbg ) {
    debug = dbg;
    if( debug ) {
        std::cout << "Debug: Lexer constructor: " << std::endl;
        std::cout << "\tDebug: " << debug << std::endl;
    }
    scanner = new Scanner( debug );
}

// destructor
Lexer::~Lexer() {
    if( debug ) {
        std::cout << "Debug: Lexer destructor: " << std::endl;
    }
    delete scanner;

}

std::string Lexer::getToken( void ) {
    return "EOF";
}

#include "Lexer.h"
#include "Scanner.h"
#include "Token.h"
#include "TokenType.h"

#include <iostream>

// constructor
Lexer::Lexer( std::string const & source, bool dbg ) {
    debug = dbg;
    ch = ' ';       // force load of first char
    if( debug ) {
        std::cout << "Debug: Lexer constructor: " << std::endl;
        std::cout << "\tDebug: " << debug << std::endl;
    }
    scanner = new Scanner( source, debug );
}

// destructor
Lexer::~Lexer() {
    if( debug ) {
        std::cout << "Debug: Lexer destructor: " << std::endl;
    }
    delete scanner;

}

void Lexer::skip( void ) {
    while( ch == ' ' || ch == '\t' || ch == '\n' )
        ch = scanner->getc();
}

Token Lexer::getToken( void ) {
    Token tok;
    std::string token = "";
    skip();
    if( isalpha( ch ) ) {
        while( isalnum( ch ) ) {
            token += ch;
            ch = scanner-> getc();
        }
        tok.setString( token );
        tok.setType( tok_IDENT );
    } else if( ch == (char)0 ) {
        tok.setString( "EOF" );
        tok.setType( tok_EOF ); 
    } else {
        token += ch;
        tok.setString( token );
        tok.setType( tok_SYMBOL );
        ch = scanner->getc();
    }
    if( debug ) std::cout << "Lexer: " << tok.getString() << std::endl;
    return tok;
}

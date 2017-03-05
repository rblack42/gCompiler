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
        token = lexer->getToken();
        std::cout << "Parser: " << token.getString() << std::endl;
        program();
        while ( true ) {
            if( token.getType() == tok_EOF ) break;
            token = lexer->getToken();
    }
    if( debug ) std::cout << "Parser: EOF\n";
    return true;
}

bool Parser::match( TokenType tok_type ) {
    if( token.getType() == tok_type ) {
        token = lexer->getToken();
        return true;
    }
    else
        return false; 
}   

bool Parser::program( void ) {
    if( !include() ) {
        ebnf_error( "include" );
        return false;
    }
    if( debug) std::cout << "Parser.program match: " << token.getString() << std::endl;
    return true;
}

bool Parser::include( void ) {
    if( !match( tok_SHARP ) ) {
        error( tok_SHARP );
        return false;
    }
    if( !match( tok_INCLUDE ) ) {
        error( tok_INCLUDE );
        return false;
    }
    if( debug) std::cout << "Parser.include match: " << token.getString() << std::endl;
    return true;
}

void Parser::error( TokenType tok_type ) {
    std::cout << "Error: " << lexer->displayType( tok_type ) << " expected";
    std::cout << "found " << token.getString() << std::endl;
}

void Parser::ebnf_error( std::string err ) {
    std::cout << "Rule failed: " << err << std:: endl;
}

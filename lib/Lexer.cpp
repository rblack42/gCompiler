#include "Lexer.h"
#include "Scanner.h"
#include "Token.h"
#include "TokenType.h"

#include <iostream>
#include <map>

// constructor
Lexer::Lexer( std::string const & source, bool dbg ) {
    debug = dbg;
    init_res_table();
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

TokenType Lexer::search( std::string sym ) {
    std::map<std::string, TokenType>::iterator rt_iter;
    rt_iter = res_table.find( sym );
    if( rt_iter != res_table.end() ) 
        return res_table.find( sym )->second;
    return tok_UNKNOWN;
}

Token Lexer::getToken( void ) {
    Token tok;
    TokenType check;
    std::string token = "";
    skip();
    if( isalpha( ch ) ) {
        while( isalnum( ch ) ) {
            token += ch;
            ch = scanner->getc();
        }
        check = search( token );
        if( check != tok_UNKNOWN )
            tok.setType( check );
        else 
            tok.setType( tok_IDENT );
        tok.setString( token );
    } else if( isdigit( ch ) ) {
        while( isdigit( ch ) ) {
            token += ch;
            ch = scanner->getc();
        }
        tok.setString( token );
        tok.setType( tok_NUMBER );
    } else if( ch == (char)0 ) {
        tok.setString( "EOF" );
        tok.setType( tok_EOF ); 
    } else {
        token += ch;

        // serch res_table for this symbol
        check = search( token );
        if( check != tok_UNKNOWN ) tok.setType( check );
        else tok.setType( tok_SYMBOL );
        tok.setString( token );
        ch = scanner->getc();
    }
    if( debug ) std::cout << "Lexer: " << tok.getString() << std::endl;
    if( debug ) std::cout << "\ttype: " << displayType( tok.getType() ) << std::endl;
    return tok;
}

void Lexer::init_res_table( void ) {
    res_table["include"] = tok_INCLUDE;
    res_table["int"] = tok_INT;
    res_table["if"] = tok_IF;
    res_table["while"] = tok_WHILE;
    res_table[";"] = tok_SEMICOLON;
    res_table["\""] = tok_DQUOTE;
    res_table[","] = tok_COMMA;
    res_table["."] = tok_DOT;
    res_table["#"] = tok_SHARP;
    res_table["<"] = tok_LANGLE;
    res_table[">"] = tok_RANGLE;
    res_table["{"] = tok_LBRACE;
    res_table["}"] = tok_RBRACE;
    res_table["("] = tok_LBRACE;
    res_table[")"] = tok_RPAREN;

}

std::string Lexer::displayType( TokenType token ) {
    switch( token ) {
        case tok_UNKNOWN:   return "UNKNOWN";
        case tok_IDENT:     return "IDENT";
        case tok_NUMBER:    return "NUMBER";
        case tok_IF:        return "IF";
        case tok_WHILE:     return "WHILE";
        case tok_INT:       return "INT";
        case tok_INCLUDE:   return "INCLUDE";
        case tok_SEMICOLON: return "SEMICOLON";
        case tok_DQUOTE:    return "DQUOTE";
        case tok_DOT:       return "DOT";
        case tok_COMMA:     return "COMMA";
        case tok_SHARP:     return "SHARP";
        case tok_LANGLE:    return "LANGLE";
        case tok_RANGLE:    return "RANGLE";
        case tok_LBRACE:    return "LBRACE";
        case tok_RBRACE:    return "RBRACE";
        case tok_LPAREN:    return "LPAREN";
        case tok_RPAREN:    return "RPAREN";
        case tok_SYMBOL:    return "SYMBOL";
        default: return "UNKNOWN";
    }
}


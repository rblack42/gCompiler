#include "Scanner.h"

#include <iostream>

// constructor
Scanner::Scanner( std::string const & scode, bool dbg ) {
    debug = dbg;
    source = scode;
    size = source.length();
    if( debug ) 
        std::cout << "Debug: Scanner constructor\n";
}

// destructor
Scanner::~Scanner() {
    if( debug ) 
        std::cout << "Debug: Scanner destructor\n";
}

char Scanner::getc( void ) {
    if( cc < size ) {
        ch = source[cc];
        cc++;
    } else
        ch = (char)0;
    return ch;
}



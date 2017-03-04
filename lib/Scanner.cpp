#include "Scanner.h"

#include <iostream>

// constructor
Scanner::Scanner( bool dbg ) {
    debug = dbg;
    if( debug ) 
        std::cout << "Debug: Scanner constructor\n";
}

// destructor
Scanner::~Scanner() {
    if( debug ) 
        std::cout << "Debug: Scanner destructor\n";
}


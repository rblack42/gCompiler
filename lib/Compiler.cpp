#include "Compiler.h"

#include <iostream>
#include <fstream>

// constructor

// process user file name
Compiler::Compiler( std::string fn, const std::string code, bool dbg ) {
    debug = dbg;
    // if the file name string is empty, we are processing a user string
    if (fn == "") {
        file_name = "string";
        source_code = code;
        size = source_code.length();
    } else {
        // process the user file
        file_name = fn;
        // load source code into buffer
        std::ifstream fin( file_name );
        if( fin ) {
            fin.seekg(0, std::ios::end);    // find the end of the file
            size = fin.tellg();             // get the number of bytes in the file
            std::string buffer(size, ' ');  // create buffer of the required size
            fin.seekg(0, std::ios::beg);    // reset the file to the first char
            fin.read(&buffer[0], size);
            fin.close();
            source_code = buffer;          // copy buffer into place
        }
        else {
            std::cout<< "Error: source file not found: " 
                << file_name << std::endl;
            exit(0);
        }
    }  
    if( debug ) {
        std::cout << "Debug: Compiler constructor: " << std::endl;
        std::cout << "\tfile: " << file_name << std::endl;
        std::cout << "\tsize: " << size << std::endl;
        std::cout << "\tDebug: " << debug << std::endl;
    }
}

// destructor 

Compiler::~Compiler() {
    if( debug ) {
        std::cout << "Debug: Compiler destructor" << std::endl;
        delete parser;
    }
}

// accessors

std::string Compiler::getName( void ) {
    return file_name;
}

int Compiler::getSize( void ) {
    return size;
}

// mutators

bool Compiler::run( void ) {
    int i = 0;
    char ch;
    Parser* parser = new Parser( &source_code, debug );
    
    std::cout<< "Compiler succeeded" << std::endl;
    return true;
}

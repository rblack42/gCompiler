#include <iostream>
#include "Compiler.h"

const char name[] = "gCompiler";
const char version[] = "v0.1";

bool debug = false;
const char * file_name = "tests/test.c";

void usage( void ) {
    std::cout << "usage: " << name;
    std::cout << " [-d] ";
    std::cout << " file_name\n";
}

void checkArgs( int argc, char *argv[] ) {
    for (int i=1;i<argc; i++ ) {
        if( argv[i][0] == '-') {
            if( argv[i][1] == 'd' ) debug = true;
        }
        else file_name = argv[i];
    }
}
int main( int argc, char *argv[] ) {
        if( argc < 2 ) {
            usage();
            exit(0);
        }
        std::cout << name << " " << version << std::endl;
            checkArgs( argc, argv );
        std::cout << "\tprocessing file: " << file_name << std::endl;
        if( debug ) std::cout << "\tdebugging is enabled" << std::endl;

        // activate the program
        Compiler compiler( file_name, "", debug );
        compiler.run();

        return 0;
}

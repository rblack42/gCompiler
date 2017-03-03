#include <iostream>

void usage( void ) {
    std::cout << "usage: gCompiler file_name\n";
}

int main( int argc, char *argv[] ) {
        if( argc < 2 ) {
            usage();
            exit(0);
        }
        std::cout << "gCompiler (v0.1)\n";
}

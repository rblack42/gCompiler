#include <iostream>

const char name[] = "gCompiler";
const char version[] = "v0.1";

void usage( void ) {
    std::cout << "usage: " << name << " file_name\n";
}

int main( int argc, char *argv[] ) {
        if( argc < 2 ) {
            usage();
            exit(0);
        }
        std::cout << name << " " << version << "\n"
        string file_name;
}

#include "catch.hpp"
#include "Compiler.h"

// test data for string compile test
const std::string test_code = 
    "#include <stdio.h>\n\n"
    "int main( void ) {\n"
    "\tprintf(\"Hello, World!\");\n\n"
    "\treturn 0;\n"
    "}";
int test_size = test_code.length();

// test data for file compile test
const char file_name[]  = "tests/test.c";
int file_size = 86;

// check that the constructors work
TEST_CASE( "compiler constructor test", "compiler" ) {
    Compiler c1( "", test_code, false );
    REQUIRE( c1.getSize() == test_size );

    Compiler c2( file_name, "", false );
    REQUIRE( c2.getSize() == file_size );
}


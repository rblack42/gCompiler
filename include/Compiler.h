#pragma once
#include <string>
#include "Parser.h"

class Compiler {
    public:
        // constructors
        Compiler( const std::string file_name, 
                  const std::string code, bool dgb);

        // deconstructor
        ~Compiler();

        // accessors
        std::string getName( void );
        int getSize( void );

        // mutators
        bool run( void );

    private:
        bool debug;
        std::string file_name; 
        std::string source_code;
        int size;

        Parser* parser;
};


Parser Class Design
###################

Assuming the **Compiler** class constructor has successfully set up a source
code string to process, the **Parser** will take over and attempt to process
that string. This class sets up a parser that uses the *EBNF* rules that define
the language in a simple way. Each rule becomes a method that seeks to check a
stream of *tokens*, generated by the **Lexer** class, match the defined rules
for this language.

..  literalinclude::    /include/Parser.h
    :linenos:
    :caption: Parser.h

..  vim:ft=rst spell:


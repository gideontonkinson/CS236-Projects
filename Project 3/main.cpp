#include "Lexer.h"
#include "Parser.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

int main(int argc, char** argv) {

    std::ifstream in;
    in.open(argv[1]);
    std::ostringstream sstr;
    sstr << in.rdbuf();
    std::string s = sstr.str();

    Lexer* lexer = new Lexer();

    lexer->Run(s);
    Parser* parser = new Parser(lexer->Tokens());
    parser->parse();

    delete lexer;
    delete parser;

    return 0;
}
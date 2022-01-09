#include "Lexer.h"
#include "Parser.h"
#include "Interpreter.h"
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

    auto* lexer = new Lexer();

    lexer->Run(s);
    auto* parser = new Parser(lexer->Tokens());
    auto* interpreter = new Interpreter(parser->parse());

    delete lexer;
    delete parser;
    delete interpreter; //No memory leaks

    return 0;
}

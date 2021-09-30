#include "Lexer.h"
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
    std::cout << lexer->toString();

    delete lexer;

    return 0;
}
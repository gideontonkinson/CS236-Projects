#include "Lexer.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

int main(int argc, char** argv) {

    std::fstream in(argv[1]);

    std::filebuf* pbuf = in.rdbuf();

    std::size_t size = pbuf->pubseekoff (0,in.end,in.in);
    pbuf->pubseekpos (0,in.in);

    // Allocate memory to contain file data
    char* buffer=new char[size];

    // Get file data
    pbuf->sgetn (buffer,size);

    in.close();

    // Write content to ss
    std::stringstream ss;
    ss.str(buffer);

    //No memory leaks
    delete[] buffer;
    std::string s = ss.str();

    Lexer* lexer = new Lexer();

    lexer->Run(s);
    std::cout << lexer->toString();

    delete lexer;

    return 0;
}
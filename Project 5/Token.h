#ifndef TOKEN_H
#define TOKEN_H
#include <string>

enum class TokenType {
    COLON,
    COLON_DASH,
    COMMA,
    PERIOD,
    Q_MARK,
    LEFT_PAREN,
    RIGHT_PAREN,
    MULTIPLY,
    ADD,
    SCHEMES,
    FACTS,
    RULES,
    QUERIES,
    ID,
    STRING,
    COMMENT,
    UNDEFINED,
    FINISHED
};

class Token
{
private:
    TokenType type;
    std::string value;
    int line;

public:
    Token(TokenType type, std::string description, int line);
    std::string typeOfToken();
    std::string valueOfToken();
    std::string toString();

    // TODO: add other needed methods
};

#endif // TOKEN_H


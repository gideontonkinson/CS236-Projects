#include "Token.h"

Token::Token(TokenType type, std::string description, int line) {
    this->type = type;
    this->value = description;
    this->line = line;
}

std::string Token::toString() {
    std::string s = "";
    s += "(";
    //Prints the correct type of Token
    switch (type) {
        case TokenType::COLON:
            s += "COLON";
            break;
        case TokenType::COLON_DASH:
            s += "COLON_DASH";
            break;
        case TokenType::COMMA:
            s += "COMMA";
            break;
        case TokenType::PERIOD:
            s += "PERIOD";
            break;
        case TokenType::Q_MARK:
            s += "Q_MARK";
            break;
        case TokenType::LEFT_PAREN:
            s += "LEFT_PAREN";
            break;
        case TokenType::RIGHT_PAREN:
            s += "RIGHT_PAREN";
            break;
        case TokenType::MULTIPLY:
            s += "MULTIPLY";
            break;
        case TokenType::ADD:
            s += "ADD";
            break;
        case TokenType::SCHEMES:
            s += "SCHEMES";
            break;
        case TokenType::FACTS:
            s += "FACTS";
            break;
        case TokenType::RULES:
            s += "RULES";
            break;
        case TokenType::QUERIES:
            s += "QUERIES";
            break;
        case TokenType::ID:
            s += "ID";
            break;
        case TokenType::STRING:
            s += "STRING";
            break;
        case TokenType::COMMENT:
            s += "COMMENT";
            break;
        case TokenType::UNDEFINED:
            s += "UNDEFINED";
            break;
        case TokenType::FINISHED:
            s += "EOF";
            break;
    }
    s += ",\"" + value + "\"," + std::to_string(line) + ")";
    return s;

}

#include "Token.h"

Token::Token(TokenType type, std::string description, int line) {
    this->type = type;
    this->value = description;
    this->line = line;
}

std::string Token::typeOfToken() {
    //Prints the correct type of Token
    switch (type) {
        case TokenType::COLON:
            return "COLON";
            break;
        case TokenType::COLON_DASH:
            return "COLON_DASH";
            break;
        case TokenType::COMMA:
            return "COMMA";
            break;
        case TokenType::PERIOD:
            return "PERIOD";
            break;
        case TokenType::Q_MARK:
            return "Q_MARK";
            break;
        case TokenType::LEFT_PAREN:
            return "LEFT_PAREN";
            break;
        case TokenType::RIGHT_PAREN:
            return "RIGHT_PAREN";
            break;
        case TokenType::MULTIPLY:
            return "MULTIPLY";
            break;
        case TokenType::ADD:
            return "ADD";
            break;
        case TokenType::SCHEMES:
            return "SCHEMES";
            break;
        case TokenType::FACTS:
            return "FACTS";
            break;
        case TokenType::RULES:
            return "RULES";
            break;
        case TokenType::QUERIES:
            return "QUERIES";
            break;
        case TokenType::ID:
            return "ID";
            break;
        case TokenType::STRING:
            return "STRING";
            break;
        case TokenType::COMMENT:
            return "COMMENT";
            break;
        case TokenType::UNDEFINED:
            return "UNDEFINED";
            break;
        case TokenType::FINISHED:
            return "EOF";
            break;
    }
    return "ERROR";
}

std::string Token::valueOfToken() {
    return value;
}

std::string Token::toString() {
    std::string s = "(";
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

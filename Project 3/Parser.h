//
// Created by Gideon Tonkinson on 9/28/21.
//

#ifndef PROJECT_2_PARSER_H
#define PROJECT_2_PARSER_H
#include "Token.h"
#include "Predicate.h"
#include "Rule.h"
#include "DatalogProgram.h"
#include <vector>
#include <set>

class Parser {
private:
    std::vector<Token*> tokens;
    int i;
    DatalogProgram* parseDatalogProgram();
    std::vector <Predicate*> parseSchemeList();
    std::vector <Predicate*> parseFactList();
    std::vector <Rule*> parseRuleList();
    std::vector <Predicate*> parseQuerylist();
    Predicate* parseScheme();
    Predicate* parseFact();
    Rule* parseRule();
    Predicate* parseQuery();
    Predicate* parseHeadPredicate ();
    Predicate* parsePredicate ();
    std::vector <Predicate*> parsePredicateList();
    std::vector<Parameter*> parseParameterList();
    std::vector<Parameter*> parseStringList();
    std::vector<Parameter*> parseIDList();
    Parameter* parseParameter();
    bool match(Token* t, std::string s);

public:
    Parser(const std::vector<Token *> &tokens);
    std::string toString();
    ~Parser();

    void parse();

};


#endif //PROJECT_2_PARSER_H

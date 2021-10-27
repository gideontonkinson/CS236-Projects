//
// Created by Gideon Tonkinson on 9/28/21.
//

#include <iostream>
#include "Parser.h"

Parser::Parser(const std::vector<Token *> &tokens) {
    this->tokens = tokens;
    i = 0;
}

Parser::~Parser(){
}

bool Parser::match(Token* t, std::string s) {
    if(t->typeOfToken() == s){
        return true;
    } else {
        return false;
    }
}

void Parser::parse() {
    try{
        DatalogProgram* datalog = parseDatalogProgram();
        std::cout << datalog->toString();
    } catch(Token* r) {
        std::cout << "Failure!\n";
        std::cout << "   " << r->toString();
    }
}

DatalogProgram* Parser::parseDatalogProgram() {
    //datalogProgram	->	SCHEMES COLON scheme schemeList FACTS COLON factList RULES COLON ruleList QUERIES COLON query queryList EOF
        DatalogProgram* datalog = new DatalogProgram();
        if (match(tokens[i], "SCHEMES")) {
        } else{
            throw tokens[i];
        }
        if (match(tokens[i + 1], "COLON")) {
            i++;
        } else {
            throw tokens[i+1];
        }
        datalog->addScheme(parseScheme());
        datalog->addSchemeList(parseSchemeList());
        if (match(tokens[i + 1], "FACTS")) {
            i++;
        } else {
            throw tokens[i+1];
        }
        if (match(tokens[i + 1], "COLON")) {
            i++;
        } else {
            throw tokens[i+1];
        }
        datalog->addFactList(parseFactList());
        if (match(tokens[i + 1], "RULES")) {
            i++;
        } else {
            throw tokens[i+1];
        }
        if (match(tokens[i + 1], "COLON")) {
            i++;
        } else {
            throw tokens[i+1];
        }
        datalog->addRuleList(parseRuleList());
        if (match(tokens[i + 1], "QUERIES")) {
            i++;
        } else {
            throw tokens[i+1];
        }
        if (match(tokens[i + 1], "COLON")) {
            i++;
        } else {
            throw tokens[i+1];
        }
        datalog->addQuery(parseQuery());
        datalog->addQueryList(parseQuerylist());
        if (match(tokens[i + 1], "EOF")) {
            i++;
        } else {
            throw tokens[i+1];
        }
        datalog->makeDomains();
    return datalog;
}

std::vector <Predicate*> Parser::parseSchemeList() {
    //schemeList	->	scheme schemeList | lambda
    std::vector <Predicate*> schemeList;
    if(match(tokens[i+1], "ID")){
        schemeList.push_back(parseScheme());
        std::vector <Predicate*> temp = parseSchemeList();
        schemeList.insert(schemeList.end(), temp.begin(), temp.end());
    }
    else if(match(tokens[i+1], "FACTS")){
    } else{
        throw tokens[i+1];
    }
    return schemeList;
}

std::vector <Predicate*> Parser::parseFactList() {
    //factList	->	fact factList | lambda
    std::vector <Predicate*> factList;
    if(match(tokens[i+1], "ID")){
        factList.push_back(parseFact());
        std::vector <Predicate*> temp = parseFactList();
        factList.insert(factList.end(), temp.begin(), temp.end());
    }
    else if(match(tokens[i+1], "RULES")){
    } else{
        throw tokens[i+1];
    }
    return factList;
}

std::vector <Rule*> Parser::parseRuleList() {
    //ruleList	->	rule ruleList | lambda
    std::vector <Rule*> ruleList;
    if(match(tokens[i+1], "ID")){
        ruleList.push_back(parseRule());
        std::vector <Rule*> temp = parseRuleList();
        ruleList.insert(ruleList.end(), temp.begin(), temp.end());
    }
    else if(match(tokens[i+1], "QUERIES")){
    } else{
        throw tokens[i+1];
    }
    return ruleList;
}

std::vector <Predicate*> Parser::parseQuerylist() {
    //queryList	->	query queryList | lambda
    std::vector <Predicate*> queryList;
    if(match(tokens[i+1], "ID")){
        queryList.push_back(parseQuery());
        std::vector <Predicate*> temp = parseQuerylist();
        queryList.insert(queryList.end(), temp.begin(), temp.end());
    }
    else if(match(tokens[i+1], "EOF")){
    } else{
        throw tokens[i+1];
    }
    return queryList;
}

Predicate* Parser::parseScheme() {
    //scheme -> ID LEFT_PAREN ID idList RIGHT_PAREN
    Predicate* scheme = new Predicate(tokens[i+1]->valueOfToken());
    if(match(tokens[i+1], "ID")){
        i++;
    } else{
        throw tokens[i+1];
    }
    if(match(tokens[i+1], "LEFT_PAREN")){
        i++;
    } else{
        throw tokens[i+1];
    }
    if(match(tokens[i+1], "ID")){
        scheme->addParams(parseParameter());
    } else{
        throw tokens[i+1];
    }
    scheme->addParamList(parseIDList());
    if(match(tokens[i+1], "RIGHT_PAREN")){
        i++;
    } else{
        throw tokens[i+1];
    }
    return scheme;
}

Predicate* Parser::parseFact() {
    //fact -> ID LEFT_PAREN STRING stringList RIGHT_PAREN PERIOD
    Predicate* fact = new Predicate(tokens[i+1]->valueOfToken());
    if(match(tokens[i+1], "ID")){
        i++;
    } else{
        throw tokens[i+1];
    }
    if(match(tokens[i+1], "LEFT_PAREN")){
        i++;
    } else {
        throw tokens[i+1];
    }
    if(match(tokens[i+1], "STRING")){
        fact->addParams(parseParameter());
    } else{
        throw tokens[i+1];
    }
    fact->addParamList(parseStringList());
    if(match(tokens[i+1], "RIGHT_PAREN")){
        i++;
    } else {
        throw tokens[i+1];
    }
    if(match(tokens[i+1], "PERIOD")){
        i++;
    } else {
        throw tokens[i+1];
    }
    return fact;
}

Rule* Parser::parseRule() {
    //rule -> headPredicate COLON_DASH predicate predicateList PERIOD
    Rule* rule = new Rule(parseHeadPredicate());
    if(match(tokens[i+1], "COLON_DASH")){
        i++;
    } else{
        throw tokens[i+1];
    }
    rule->addPred(parsePredicate());
    rule->addPredList(parsePredicateList());
    if(match(tokens[i+1], "PERIOD")){
        i++;
    } else{
        throw tokens[i+1];
    }
    return rule;
}

Predicate* Parser::parseQuery() {
   //query -> predicate Q_MARK
    Predicate* query = parsePredicate();
    if(match(tokens[i+1], "Q_MARK")){
        i++;
    } else{
        throw tokens[i+1];
    }
    return query;
}

Predicate* Parser::parseHeadPredicate() {
    //headPredicate -> ID LEFT_PAREN ID idList RIGHT_PAREN
    Predicate* headPredicate =  new Predicate(tokens[i+1]->valueOfToken());
    if(match(tokens[i+1], "ID")){
        i++;
    } else{
        throw tokens[i+1];
    }
    if(match(tokens[i+1], "LEFT_PAREN")){
        i++;
    } else{
        throw tokens[i+1];
    }
    if(match(tokens[i+1], "ID")){
        headPredicate->addParams(parseParameter());
    } else{
        throw tokens[i+1];
    }
    headPredicate->addParamList(parseIDList());
    if(match(tokens[i+1], "RIGHT_PAREN")){
        i++;
    } else{
        throw tokens[i+1];
    }
    return headPredicate;
}

Predicate* Parser::parsePredicate() {
    //predicate	->	ID LEFT_PAREN parameter parameterList RIGHT_PAREN
    Predicate* predicate =  new Predicate(tokens[i+1]->valueOfToken());
    if(match(tokens[i+1], "ID")){
        i++;
    } else{
        throw tokens[i+1];
    }
    if(match(tokens[i+1], "LEFT_PAREN")){
        i++;
    } else{
        throw tokens[i+1];
    }
    predicate->addParams(parseParameter());
    predicate->addParamList(parseParameterList());
    if(match(tokens[i+1], "RIGHT_PAREN")){
        i++;
    } else{
        throw tokens[i+1];
    }
    return predicate;
}

std::vector <Predicate*> Parser::parsePredicateList() {
    //predicateList	->	COMMA predicate predicateList | lambda
    std::vector <Predicate*> predicateList;
    if(match(tokens[i+1], "COMMA")){
        i++;
        predicateList.push_back(parsePredicate());
        std::vector <Predicate*> temp = parsePredicateList();
        predicateList.insert( predicateList.end(), temp.begin(), temp.end());
        if(match(tokens[i+1], "RIGHT_PAREN")){
            i++;
        }
    }
    else if(match(tokens[i+1], "PERIOD")){
    } else{
        throw tokens[i+1];
    }
    return predicateList;
}

std::vector <Parameter*> Parser::parseParameterList() {
    //parameterList	-> 	COMMA parameter parameterList | lambda
    std::vector <Parameter*> paramList;
    if(match(tokens[i+1], "COMMA")){
        i++;
        paramList.push_back(parseParameter());
        std::vector<Parameter*> temp = parseParameterList();
        paramList.insert( paramList.end(), temp.begin(), temp.end());
    }
    else if(match(tokens[i+1], "RIGHT_PAREN")){
    } else{
        throw tokens[i+1];
    }
    return paramList;
}

std::vector <Parameter*> Parser::parseStringList() {
    //stringList -> COMMA STRING stringList | lambda
    std::vector <Parameter*> stringList;
    if(match(tokens[i+1], "COMMA")){
        i++;
        if(match(tokens[i+1], "STRING")){
            stringList.push_back(parseParameter());
        } else{
            throw tokens[i+1];
        }
        std::vector<Parameter*> temp = parseStringList();
        stringList.insert( stringList.end(), temp.begin(), temp.end());
    }
    else if(match(tokens[i+1], "RIGHT_PAREN")){
    } else{
        throw tokens[i+1];
    }
    return stringList;
}

std::vector <Parameter*> Parser::parseIDList() {
    //idList  	-> 	COMMA ID idList | lambda
    std::vector <Parameter*> IDList;
    if(match(tokens[i+1], "COMMA")){
        i++;
        if(match(tokens[i+1], "ID")){
            IDList.push_back(parseParameter());
        } else{
            throw tokens[i+1];
        }
        std::vector<Parameter*> temp = parseIDList();
        IDList.insert( IDList.end(), temp.begin(), temp.end());
    }
    else if(match(tokens[i+1], "RIGHT_PAREN")){
    } else{
        throw tokens[i+1];
    }
    return IDList;
}

Parameter* Parser::parseParameter() {
    //parameter	->	STRING | ID
    if(match(tokens[i+1], "STRING")){
        i++;
        return new Parameter(tokens[i]->valueOfToken());
    } else if (match(tokens[i+1], "ID")) {
        i++;
        return new Parameter(tokens[i]->valueOfToken());
    } else {
            throw tokens[i+1];
    }
}
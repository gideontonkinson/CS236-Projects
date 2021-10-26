//
// Created by Gideon Tonkinson on 9/29/21.
//

#include "DatalogProgram.h"

DatalogProgram::DatalogProgram() {}

void DatalogProgram::addFact(Predicate *fact) {
    facts.push_back(fact);
}

void DatalogProgram::addFactList(std::vector<Predicate *> factList) {
    facts.insert(facts.end(), factList.begin(), factList.end());
}

void DatalogProgram::addQuery(Predicate *query) {
    queries.push_back(query);
}

void DatalogProgram::addQueryList(std::vector<Predicate *> queryList) {
    queries.insert(queries.end(), queryList.begin(), queryList.end());
}

void DatalogProgram::addRule(Rule *rule) {
    rules.push_back(rule);
}

void DatalogProgram::addRuleList(std::vector<Rule *> ruleList) {
    rules.insert(rules.end(), ruleList.begin(), ruleList.end());
}

void DatalogProgram::addScheme(Predicate *scheme) {
    schemes.push_back(scheme);
}

void DatalogProgram::addSchemeList(std::vector<Predicate *> schemeList) {
    schemes.insert(schemes.end(), schemeList.begin(), schemeList.end());
}

void DatalogProgram::getDomains() {
    for(size_t i = 0; i < facts.size(); i++){
        std::vector<Parameter*> params = facts.at(i)->getParamas();
        for(size_t j = 0; j < params.size(); j++){
            domains.insert(params.at(j)->toString());
        }
    }
}

std::string DatalogProgram::toString() {
    std::string s = "Success!\n";
    s += "Schemes(" + std::to_string(schemes.size());
    s += "):\n";
    for(size_t i = 0; i < schemes.size(); i++){
        s+= "   " + schemes.at(i)->toString() += "\n";
    }
    s += "Facts(" + std::to_string(facts.size());
    s += "):\n";
    for(size_t i = 0; i < facts.size(); i++){
        s+= "   " + facts.at(i)->toString() += ".\n";
    }
    s += "Rules(" + std::to_string(rules.size());
    s += "):\n";
    for(size_t i = 0; i < rules.size(); i++){
        s+= "   " + rules.at(i)->toString() += "\n";
    }
    s += "Queries(" + std::to_string(queries.size());
    s += "):\n";
    for(size_t i = 0; i < queries.size(); i++){
        s+= "   " + queries.at(i)->toString() += "?\n";
    }
    s += "Domain(" + std::to_string(domains.size());
    s += "):\n";
    for(auto d : domains){
        s+= "   " + d += "\n";
    }
    return s;
}
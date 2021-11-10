//
// Created by Gideon Tonkinson on 9/29/21.
//

#ifndef PROJECT_2_DATALOGPROGRAM_H
#define PROJECT_2_DATALOGPROGRAM_H
#include "Predicate.h"
#include "Rule.h"
#include "Parameter.h"
#include <vector>
#include <set>

class DatalogProgram {
private:
    std::vector<Predicate*> schemes;
    std::vector<Predicate*> facts;
    std::vector<Predicate*> queries;
    std::vector<Rule*> rules;
    std::set<std::string> domains;
public:
    DatalogProgram();
    void addScheme(Predicate* scheme);
    void addSchemeList(std::vector<Predicate*> schemeList);
    std::vector<Predicate*> getSchemes();
    void addFact(Predicate* fact);
    void addFactList(std::vector<Predicate*> factList);
    std::vector<Predicate*> getFacts();
    void addQuery(Predicate* query);
    void addQueryList(std::vector<Predicate*> queryList);
    std::vector<Predicate*> getQueries();
    void addRule(Rule* rule);
    void addRuleList(std::vector<Rule*> ruleList);
    std::vector<Rule*> getRules();
    void makeDomains();
    std::set<std::string> getDomains();
    std::string toString();
};


#endif //PROJECT_2_DATALOGPROGRAM_H

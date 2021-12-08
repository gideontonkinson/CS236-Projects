//
// Created by Gideon Tonkinson on 9/28/21.
//

#ifndef PROJECT_3_RULE_H
#define PROJECT_3_RULE_H
#include "Predicate.h"
#include <vector>


class Rule {
private:
    Predicate* headPredicate;
    std::vector<Predicate*> bodyPredicates;
    bool visited;
public:
    Rule(Predicate* headPredicate);
    std::string toString();
    void addPredList(std::vector<Predicate*> bodyPreds);
    void addPred(Predicate* pred);
    bool isVisited();
    void visit();
    void unvisit();
    Predicate* getHeadPred();
    std::vector<Predicate*> getBodyPreds();
};


#endif //PROJECT_3_RULE_H

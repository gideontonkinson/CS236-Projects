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
public:
    Rule(Predicate* headPredicate);
    std::string toString();
    void addPredList(std::vector<Predicate*> bodyPreds);
    void addPred(Predicate* pred);
};


#endif //PROJECT_3_RULE_H

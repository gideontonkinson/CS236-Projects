//
// Created by Gideon Tonkinson on 9/28/21.
//

#ifndef PROJECT_2_RULE_H
#define PROJECT_2_RULE_H
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


#endif //PROJECT_2_RULE_H

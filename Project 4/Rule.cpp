//
// Created by Gideon Tonkinson on 9/28/21.
//

#include "Rule.h"

Rule::Rule(Predicate *headPredicate) {
    this->headPredicate = headPredicate;
}

void Rule::addPred(Predicate *pred) {
    bodyPredicates.push_back(pred);
}

void Rule::addPredList(std::vector<Predicate *> bodyPreds) {
    bodyPredicates.insert( bodyPredicates.end(), bodyPreds.begin(), bodyPreds.end());
}

std::string Rule::toString() {
    std::string s = headPredicate->toString() + " :- ";
    for(size_t i = 0; i < bodyPredicates.size()-1; i++){
        s+= bodyPredicates.at(i)->toString() + ",";
    }
    s += bodyPredicates.at(bodyPredicates.size()-1)->toString();
    s+= ".";
    return s;
}

Predicate *Rule::getHeadPred() {
    return headPredicate;
}

std::vector<Predicate *> Rule::getBodyPreds() {
    return bodyPredicates;
}

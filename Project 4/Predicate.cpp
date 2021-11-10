//
// Created by Gideon Tonkinson on 9/28/21.
//

#include "Predicate.h"

Predicate::Predicate(std::string id) {
    this->id = id;
}

std::string Predicate::toString() {
    std::string s = id + "(";
    for(size_t i = 0; i < parameters.size()-1; i++){
        s += parameters[i]->toString() + ",";
    }
    s+= parameters.at(parameters.size()-1)->toString() + ")";
    return s;
}

void Predicate::addParams(Parameter* p) {
    parameters.push_back(p);
}

void Predicate::addParamList(std::vector<Parameter*> paramList){
    parameters.insert( parameters.end(), paramList.begin(), paramList.end());
}

std::vector<Parameter *> Predicate::getParamas() {
    return parameters;
}

std::string Predicate::getID() {
    return id;
}

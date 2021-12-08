//
// Created by Gideon Tonkinson on 9/28/21.
//

#ifndef PROJECT_2_PREDICATE_H
#define PROJECT_2_PREDICATE_H
#include <string>
#include <vector>
#include "Parameter.h"


class Predicate {
private:
    std::string id;
    std::vector<Parameter*> parameters;
public:
    Predicate(std::string id);
    std::string toString();
    void addParams(Parameter* p);
    void addParamList(std::vector<Parameter*> pl);
    std::vector<Parameter*> getParamas();
    std::string getID();
};


#endif //PROJECT_2_PREDICATE_H

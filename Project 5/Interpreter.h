//
// Created by Gideon Tonkinson on 10/26/21.
//

#ifndef PROJECT_3_INTERPRETER_H
#define PROJECT_3_INTERPRETER_H
#include <iostream>
#include "DatalogProgram.h"
#include "Database.h"
#include "Relation.h"
#include "Graph.h"

class Interpreter {
private:
    DatalogProgram* datalogProgram;
    Database database;
    Graph* rGraph;
    Graph* graph;

public:
    Interpreter(DatalogProgram* datalogProgram);
    void makeRelations();
    void makeTuples();
    Relation* evaluatePredicate(Predicate* p);
    void evaluateRule(Rule* rule);
    void evaluateRules();
    void evaluateQueries();
    void SCCToString(size_t i);
};


#endif //PROJECT_3_INTERPRETER_H

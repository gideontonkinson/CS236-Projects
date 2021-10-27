//
// Created by Gideon Tonkinson on 10/26/21.
//

#ifndef PROJECT_3_INTERPRETER_H
#define PROJECT_3_INTERPRETER_H
#include "DatalogProgram.h"
#include "Database.h"
#include "Relation.h"

class Interpreter {
private:
    DatalogProgram datalogProgram;
    Database database;

public:
    Interpreter(DatalogProgram datalogProgram);
    Relation* evalutePredicate(Predicate& p);
    void makeRelations();
    void makeTuples();

};


#endif //PROJECT_3_INTERPRETER_H

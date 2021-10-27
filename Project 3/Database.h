//
// Created by Gideon Tonkinson on 10/26/21.
//

#ifndef PROJECT_3_DATABASE_H
#define PROJECT_3_DATABASE_H
#include<map>
#include "Relation.h"

class Database {
private:
std::map<std::string, Relation> relations;
};


#endif //PROJECT_3_DATABASE_H

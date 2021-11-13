//
// Created by Gideon Tonkinson on 10/26/21.
//

#ifndef PROJECT_3_DATABASE_H
#define PROJECT_3_DATABASE_H
#include<map>
#include "Relation.h"

class Database {
private:
    std::map<std::string, Relation*> relations;
public:
    void add(std::string s, Relation* r);
    Relation* at(std::string);
    size_t size();
};


#endif //PROJECT_3_DATABASE_H

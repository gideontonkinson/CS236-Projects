//
// Created by Gideon Tonkinson on 10/26/21.
//

#include "Database.h"

void Database::add(std::string s, Relation* r) {
    relations.insert({s,r});
}

Relation* Database::at(std::string s) {
     return relations.at(s);
}
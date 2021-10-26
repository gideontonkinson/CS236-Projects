//
// Created by Gideon Tonkinson on 10/25/21.
//

#ifndef PROJECT_3_RELATION_H
#define PROJECT_3_RELATION_H
#include <string>
#include <set>
#include "Header.h"
#include "Tuple.h"

class Relation {
private:
    std::string name;
    Header* header;
    std::set<Tuple> rows;
public:
    Relation();
    Relation select(int index, std::string value);
    Relation select(int index1, int index2);
    Relation project(std::vector<int> indices);
    Relation rename(std::vector<std::string> attributes);
};


#endif //PROJECT_3_RELATION_H

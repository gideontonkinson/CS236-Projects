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
    Relation(std::string name, Header* header);
    Relation* select(size_t index, std::string value);
    Relation* select(size_t index1, size_t index2);
    Relation* project(std::vector<size_t> indices);
    Relation* rename(std::vector<std::string> attributes);
    Relation* join(Relation* r);
    Relation* unite(Relation* r);
    Header combineHeaders(Relation* r);
    bool isJoinable(Relation*r );
    Tuple combineTuples(Relation* r);
    bool addTuple(Tuple t);
    size_t numRows();
    std::string toString();
};


#endif //PROJECT_3_RELATION_H

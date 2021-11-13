//
// Created by Gideon Tonkinson on 10/25/21.
//

#ifndef PROJECT_3_RELATION_H
#define PROJECT_3_RELATION_H
#include <string>
#include <set>
#include <map>
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
    std::string unite(Relation* r);
    bool isJoinable(Tuple& t1, Tuple& t2, const std::map <size_t, size_t> &m);
    Tuple combineTuples(Tuple& t1, Tuple& t2, const std::map <size_t, size_t> &m);
    bool addTuple(Tuple t);
    Header* getHeader();
    size_t numRows();
    std::string toString();
};


#endif //PROJECT_3_RELATION_H

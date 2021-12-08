//
// Created by Gideon Tonkinson on 10/25/21.
//

#include "Relation.h"

Relation::Relation(std::string name, Header *header) {
    this->name = name;
    this->header = header;
}

Relation* Relation::select(size_t index, std::string value) {
    Relation* r = new Relation(name, header);
    for(Tuple t : rows){
        if(t.at(index) == value){
            r->addTuple(t);
        }
    }
    return r;
}

Relation *Relation::select(size_t index1, size_t index2) {
    Relation* r = new Relation(name, header);
    for(Tuple t : rows){
        if(t.at(index1) == t.at(index2)){
            r->addTuple(t);
        }
    }
    return r;
}

Relation *Relation::project(std::vector<size_t> indices) {
    Header* h = new Header();
    for (size_t j = 0; j < indices.size(); j++) {
        for (size_t i= 0; i < header->size(); i++) {
            if (indices.at(j) == i) {
                h->addAttributes(header->at(i));
            }
        }
    }
    Relation* r = new Relation(name, h);
    for(Tuple t : rows){
        Tuple newT;
        for (size_t j = 0; j < indices.size(); j++) {
            for(size_t i = 0; i < header->size(); i++) {
                if (indices.at(j) == i) {
                    newT.addValue(t.at(i));
                }
            }
        }
        r->addTuple(newT);
    }
    return r;
}

Relation *Relation::rename(std::vector<std::string> attributes) {
    Header* h = new Header();
    for(size_t i = 0; i < header->size(); i++){
        h->addAttributes(attributes.at(i));
    }
    Relation* r = new Relation(name, h);
    for(Tuple t : rows){
        r->addTuple(t);
    }
    return r;
}

Relation *Relation::join(Relation *jR) {
    std::map<size_t, size_t> headerCorrelation;
    for(size_t i = 0; i < header->size(); i ++){
        for (size_t j = 0; j < jR->header->size(); j ++){
            if(header->at(i) == jR->header->at(j)){
                headerCorrelation.insert({i,j});
            }
        }
    }
    Header* h = header->combineHeader(jR->header, headerCorrelation);
    Relation* r = new Relation(name, h);
    for(Tuple t1 : rows){
        for(Tuple t2 : jR->rows){
            if(isJoinable(t1, t2, headerCorrelation)){
                r->addTuple(combineTuples(t1, t2, headerCorrelation));
            }
        }
    }
    return r;
}

std::string Relation::unite(Relation *r) {
    std::string output;
    bool sameHeader = false;
    if(header->size() != r->header->size())
        return output;
    for(size_t i = 0; i < header->size(); i++){
        if(header->at(i) == r->getHeader()->at(i)){
            sameHeader = true;
        } else {
            sameHeader = false;
        }
    }
    if(sameHeader){
        for(Tuple t : r->rows){
            if(addTuple(t)){
                for (size_t i = 0; i < header->size(); i++){
                    if (i == 0)
                        output += " ";
                    output += " " + header->at(i) + "=" + t.at(i);
                    if(i == header->size()-1){
                        output += "\n";
                    } else {
                        output += ",";
                    }
                }
            }
        }
    }
    return output;
}

bool Relation::isJoinable(Tuple& t1, Tuple& t2, const std::map <size_t, size_t> &m) {
    bool joinable = true;
    for(size_t i = 0; i < t1.size(); i++){
        if(joinable && m.find(i) != m.end()){
            if(t1.at(i) == t2.at(m.find(i)->second)){
                joinable = true;
            } else {
                joinable = false;
            }
        }
    }
    return joinable;
}

Tuple Relation::combineTuples(Tuple& t1, Tuple& t2, const std::map <size_t, size_t> &m) {
    Tuple t;
    std::vector<std::string> combineValues;
    for(size_t i = 0; i < t1.size() ; i++){
        combineValues.push_back(t1.at(i));
    }
    for(size_t j = 0; j < t2.size() ; j++){
        bool add = true;
        for(size_t i = 0; i < t1.size() ; i++) {
            if (add && (m.find(i) == m.end() || m.find(i)->second != j)){
                add = true;
            } else if (m.find(i)->second == j){
                add = false;
            }
        }
        if(add){
            combineValues.push_back(t2.at(j));
        }
    }
    for(std::string v : combineValues){
        t.addValue(v);
    }
    return t;
}

bool Relation::addTuple(Tuple t) {
    return rows.insert(t).second;
}

Header *Relation::getHeader() {
    return header;
}

size_t Relation::numRows() {
    return rows.size();
}

std::string Relation::toString() {
    std::string output;
    for(Tuple t : rows){
        for (size_t i = 0; i < header->size(); i++){
            if (i == 0)
                output += " ";
            output += " " + header->at(i) + "=" + t.at(i);
            if(i == header->size()-1){
                output += "\n";
            } else {
                output += ",";
            }
        }
    }
    return output;
}
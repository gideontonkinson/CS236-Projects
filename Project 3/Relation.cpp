//
// Created by Gideon Tonkinson on 10/25/21.
//

#include "Relation.h"
#include <iostream>

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
    for (size_t i= 0; i < header->size(); i++) {
        for (size_t j = 0; j < indices.size(); j++) {
            if (indices.at(j) == i) {
                h->addAttributes(header->at(i));
            }
        }
    }
    Relation* r = new Relation(name, h);
    for(Tuple t : rows){
        Tuple newT = Tuple();
        for(size_t i = 0; i < header->size(); i++) {
            for (size_t j = 0; j < indices.size(); j++) {
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

void Relation::addTuple(Tuple t) {
    rows.insert(t);
}

size_t Relation::numRows() {
    return rows.size();
}

std::string Relation::toString() {
    std::string output;
    for(Tuple t : rows){
        for (size_t i = 0; i < header->size(); i++){
            output += " " + header->at(i) + "=" + t.at(i);
            if(i == header->size()-1){
                output += "\n";
            } else {
                output += ", ";
            }
        }
    }
    return output;
}
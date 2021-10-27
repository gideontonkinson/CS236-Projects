//
// Created by Gideon Tonkinson on 10/25/21.
//

#include "Relation.h"
Relation::Relation(std::string name, Header *header) {
    this->name = name;
    this->header = header;
}

Relation* Relation::select(int index, std::string value) {
    Relation* r = new Relation(name, header);
    for(Tuple t : rows){
        if(t.at(index) == value){
            r->addTuple(t);
        }
    }
    return r;
}

Relation *Relation::select(int index1, int index2) {
    Relation* r = new Relation(name, header);
    for(Tuple t : rows){
        if(t.at(index1) == t.at(index2)){
            r->addTuple(t);
        }
    }
    return r;
}

Relation *Relation::project(std::vector<int> indices) {
    Header* h = new Header();
    for (int i= 0; i < indices.size(); i++){
        h->addAttributes(header->at(indices.at(i)));
    }
    Relation* r = new Relation(name, h);
    for(Tuple t : rows){
        Tuple newT = Tuple();
        for(int i = 0; i < indices.size(); i++){
            newT.addValue(t.at(indices.at(i)));
        }
        r->addTuple(newT);
    }
    return r;
}

Relation *Relation::rename(std::vector<std::string> attributes) {
    Relation* r = new Relation(name, header);
    for(Tuple t : rows){
        r->addTuple(t);
    }
    for(int i = 0; i < r->header->size(); i++){
        if(r->header->at(i) == attributes.at(1)){
            r->header->at(i) = attributes.at(2);
        }
    }
    return r;
}

void Relation::addTuple(Tuple t) {
    rows.insert(t);
}

std::string Relation::toString() {
    std::string output;
    for(Tuple t : rows){
        for (int i = 0; i < header->size(); i++){
            output += header->at(i) + "=" + t.at(i);
            if(i == header->size()-1){
                output += "\n";
            } else {
                output += ", ";
            }
        }
    }
    return output;
}
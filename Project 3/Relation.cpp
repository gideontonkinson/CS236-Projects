//
// Created by Gideon Tonkinson on 10/25/21.
//

#include "Relation.h"
Relation::Relation(std::string name, Header *header) {
    this->name = name;
    this->header = header;
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
//
// Created by Gideon Tonkinson on 10/25/21.
//

#include "Tuple.h"

Tuple::Tuple(){

};

void Tuple::addValue(std::string newVal) {
    values.push_back(newVal);
}

std::vector<std::string> Tuple::getValues() {
    return values;
}

bool Tuple::operator<(Tuple& rhs) const {
    if(values.at(0) < rhs.getValues().at(0)){
        return true;
    } else if (values.at(0) == rhs.getValues().at(0)){
        if(values.at(1) < rhs.getValues().at(1)){
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }
}

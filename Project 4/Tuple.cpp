//
// Created by Gideon Tonkinson on 10/25/21.
//

#include "Tuple.h"

std::string Tuple::at(int i) {
    return values.at(i);
}

size_t Tuple::size() {
    return values.size();
}

void Tuple::addValue(std::string newVal) {
    values.push_back(newVal);
}

bool Tuple::operator<(const Tuple &rhs) const {
    return this->values < rhs.values;
}

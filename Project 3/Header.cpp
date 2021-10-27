//
// Created by Gideon Tonkinson on 10/25/21.
//

#include "Header.h"

void Header::addAttributes(std::string a) {
    attributes.push_back(a);
}
std::vector<std::string>Header::getAttributes(){
    return attributes;
}

size_t Header::size() {
    return attributes.size();
}

std::string Header::at(int i) {
    return attributes.at(i);
}
//
// Created by Gideon Tonkinson on 10/25/21.
//

#include "Header.h"

void Header::addAttributes(std::string a) {
    attributes.push_back(a);
}

Header* Header::combineHeader(Header *cH, const std::map <size_t, size_t> &m) {
    Header* h = new Header();
    std::vector<std::string> combineAttributes;
    for(size_t i = 0; i < attributes.size() ; i++){
        combineAttributes.push_back(attributes.at(i));
    }
    for(size_t j = 0; j < cH->attributes.size() ; j++){
        bool add = true;
        for(size_t i = 0; i < attributes.size() ; i++) {
            if (add && (m.find(i) == m.end() || m.find(i)->second != j)){
                add = true;
            } else if (m.find(i)->second == j){
                add = false;
            }
        }
        if(add){
            combineAttributes.push_back(cH->attributes.at(j));
        }

    }
    for(std::string a : combineAttributes){
        h->addAttributes(a);
    }
    return h;
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
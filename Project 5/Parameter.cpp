//
// Created by Gideon Tonkinson on 9/28/21.
//

#include "Parameter.h"

Parameter::Parameter(std::string p) {
    this->p = p;
}

std::string Parameter::toString() {
    return p;
}
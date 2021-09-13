//
// Created by Gideon Tonkinson on 9/11/21.
//

#include "UndefinedAutomata.h"

void UndefinedAutomata::S0(const std::string& input) {
    if (input[index] == '#') {
        inputRead++;
        index++;
        S1(input);
    } else if(input[index] == '\'') {
        inputRead++;
        index++;
        S4(input);
    } else if(static_cast<int>(input.size()) != index){
        inputRead = 1;
    }
}

void UndefinedAutomata::S1(const std::string& input) {
    if (input[index] == '|') {
        inputRead++;
        index++;
        S2(input);
    }
}

void UndefinedAutomata::S2(const std::string &input) {
    if (input[index] == '|') {
        inputRead++;
        index++;
        S3(input);
    } else if (static_cast<int>(input.size()) == index) {
        inputRead++;
    } else {
        if(input[index] == '\n'){
            newLines++;
        }
        inputRead++;
        index++;
        S2(input);
    }
}

void UndefinedAutomata::S3(const std::string &input) {
    if (input[index] == '#') {
        inputRead++;
    } else {
        if(input[index] == '\n'){
            newLines++;
        }
        inputRead++;
        index++;
        S2(input);
    }
}

void UndefinedAutomata::S4(const std::string& input) {
    if (input[index] == '\'') {
        inputRead++;
        index++;
        S5(input);
    } else if(static_cast<int>(input.size()) == index) {
        inputRead++;
    } else {
        if(input[index] == '\n'){
            newLines++;
        }
        inputRead++;
        index++;
        S4(input);
    }
}

void UndefinedAutomata::S5(const std::string& input) {
    if (input[index] == '\'') {
        inputRead++;
        index++;
        S4(input);
    }
}
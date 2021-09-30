//
// Created by Gideon Tonkinson on 9/8/21.
//

#include "CommentAutomation.h"

void CommentAutomaton::S0(const std::string& input) {
    if (input[index] == '#') {
        inputRead++;
        index++;
        S1(input);
    }
    else {
        Serr();
    }
}

void CommentAutomaton::S1(const std::string& input) {
    if (input[index] == '|') {
        inputRead++;
        index++;
        S2(input);
    }
    else {
        inputRead++;
        index++;
        S3(input);
    }
}

void CommentAutomaton::S2(const std::string &input) {
    if (input[index] == '|') {
        inputRead++;
        index++;
        S4(input);

    } else if (input.size() == static_cast<size_t>(index)) {
        Serr();
    } else {
        if(input[index] == '\n'){
            newLines++;
        }
        inputRead++;
        index++;
        S2(input);
    }
}

void CommentAutomaton::S3(const std::string &input) {
    if (input[index] != '\n') {
        inputRead++;
        index++;
        S3(input);
    }
}

void CommentAutomaton::S4(const std::string& input) {
    if (input[index] == '#') {
        inputRead++;
    }
    else {
        Serr();
    }
}
//
// Created by Gideon Tonkinson on 9/9/21.
//

#ifndef PROJECT_1_EOFAUTOMATON_H
#define PROJECT_1_EOFAUTOMATON_H

#include "Automaton.h"

class EOFAutomaton : public Automaton {
public:
    EOFAutomaton() : Automaton(TokenType::FINISHED) {}  // Call the base constructor

    void S0(const std::string& input);
};


#endif //PROJECT_1_EOFAUTOMATON_H

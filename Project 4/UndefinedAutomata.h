//
// Created by Gideon Tonkinson on 9/11/21.
//

#ifndef PROJECT_1_UNDEFINEDAUTOMATA_H
#define PROJECT_1_UNDEFINEDAUTOMATA_H

#include "Automaton.h"

class UndefinedAutomata : public Automaton {
private:

    void S1(const std::string& input);

    void S2(const std::string& input);

    void S3(const std::string& input);

    void S4(const std::string& input);

    void S5(const std::string& input);

public:
    UndefinedAutomata() : Automaton(TokenType::UNDEFINED) {}  // Call the base constructor

    void S0(const std::string& input);
};


#endif //PROJECT_1_UNDEFINEDAUTOMATA_H

#include "Lexer.h"
#include "ColonAutomaton.h"
#include "ColonDashAutomaton.h"
#include "CommaAutomaton.h"
#include "PeriodAutomaton.h"
#include "QMarkAutomaton.h"
#include "LeftParenAutomaton.h"
#include "RightParenAutomaton.h"
#include "MultiplyAutomaton.h"
#include "AddAutomaton.h"
#include "SchemesAutomaton.h"
#include "FactAutomaton.h"
#include "RulesAutomaton.h"
#include "QueriesAutomaton.h"
#include "IDAutomaton.h"
#include "StringAutomaton.h"
#include "CommentAutomation.h"
#include "UndefinedAutomata.h"
#include "EOFAutomaton.h"



Lexer::Lexer() {
    CreateAutomata();
}

Lexer::~Lexer() {
    for(auto d : automata){
        delete d;
    }
    automata.clear();

    for(auto d : tokens){
        delete d;
    }
    tokens.clear();
}

void Lexer::CreateAutomata() {
    automata.push_back(new ColonAutomaton());
    automata.push_back(new ColonDashAutomaton());
    automata.push_back(new CommaAutomaton());
    automata.push_back(new PeriodAutomaton());
    automata.push_back(new QMarkAutomaton());
    automata.push_back(new LeftParenAutomaton());
    automata.push_back(new RightParenAutomaton());
    automata.push_back(new MultiplyAutomaton());
    automata.push_back(new AddAutomaton());
    automata.push_back(new SchemesAutomaton());
    automata.push_back(new FactsAutomaton());
    automata.push_back(new RulesAutomaton());
    automata.push_back(new QueriesAutomaton());
    automata.push_back(new IDAutomaton());
    automata.push_back(new StringAutomaton());
    automata.push_back(new CommentAutomaton());
    automata.push_back(new UndefinedAutomata());
    automata.push_back(new EOFAutomaton());
}

void Lexer::Run(std::string& input) {
    int lineNumber = 1;
    while(!input.empty()){
        int maxRead = 0;
        Automaton* maxAutomaton = automata.at(0);

        //Handle white space
        while(isspace(input[0])){
            if(input[0] == '\n'){
                lineNumber++;
            }
            input.erase(0,1);
        }

        for(Automaton* curr : automata){
            int inputRead = curr->Start(input);
            if(inputRead > maxRead){
                maxRead = inputRead;
                maxAutomaton = curr;
            }
        }
        if (maxRead > 0) {
            Token* newToken = maxAutomaton->CreateToken(input.substr(0, maxRead), lineNumber);
            lineNumber += maxAutomaton->NewLinesRead();
            tokens.push_back(newToken);
        }
        input.erase(0, maxRead);
    }
    tokens.push_back(automata.back()->CreateToken(input,lineNumber));
}

std::string Lexer::toString() {
    std::string s;
    for(int i = 0; static_cast<size_t >(i) < tokens.size(); i++) {
        s += tokens.at(i)->toString() + "\n";
    }
    s += "Total Tokens = ";
    s += std::to_string(tokens.size());
    return s;
}

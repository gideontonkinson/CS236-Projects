//
// Created by Gideon Tonkinson on 10/26/21.
//

#include "Interpreter.h"
#include <iostream>

Interpreter::Interpreter(DatalogProgram* datalogProgram) {
    this->datalogProgram = datalogProgram;
    makeRelations();
    makeTuples();
    for(Predicate* p : this->datalogProgram->getQueries()){
        auto* r = evaluatePredicate(p);
        std::cout << p->toString() << "? ";
        if(r->numRows() > 0) {
            std::cout << "Yes(" << r->numRows() << ")\n";
        } else {
            std::cout << "No\n";
        }
        std::cout << r->toString();
    }
}

void Interpreter::makeRelations() {
    for(Predicate* s : datalogProgram->getSchemes()){
        auto *h = new Header();
        for(size_t i = 0; i < s->getParamas().size(); i++){
            h->addAttributes(s->getParamas().at(i)->toString());
        }
        auto* r = new Relation(s->getID(), h);
        database.add(s->getID(), r);
    }
}

void Interpreter::makeTuples() {
    for(Predicate* f : datalogProgram->getFacts()){
        Tuple t = Tuple();
        for(size_t i = 0; i < f->getParamas().size(); i++){
            t.addValue(f->getParamas().at(i)->toString());
        }
        database.at(f->getID())->addTuple(t);
    }
}

Relation *Interpreter::evaluatePredicate(Predicate *p) {
    std::map<std::string, size_t> firstSeen;
    std::vector<std::string> seen;
    Relation *r = database.at(p->getID());
    //For each parameter
    for(size_t i = 0; i < p->getParamas().size(); i++){
        Parameter* param = p->getParamas().at(i);
        //Is it a constant?(Yes)
        if(param->toString().substr(0,1) == "'"){
            r = r->select(i, param->toString());
        //(No)
        } else {
            //Have we seen it? (Yes)
            if(firstSeen.find(param->toString()) != firstSeen.end()) {
                r = r->select(i, firstSeen.at(param->toString()));
            //(No)
            } else {
                seen.push_back(p->getParamas().at(i)->toString());
                firstSeen.insert({p->getParamas().at(i)->toString(), i});
            }
        }
    }

    //Project and Rename
    std::vector<size_t> projectVector;
    for(size_t i = 0; i < seen.size(); i++){
        projectVector.push_back(firstSeen.at(seen.at(i)));
    }
    r = r->project(projectVector);
    r = r->rename(seen);
    return r;
}


//
// Created by Gideon Tonkinson on 10/26/21.
//

#include "Interpreter.h"

Interpreter::Interpreter(DatalogProgram datalogProgram) {
    this->datalogProgram = datalogProgram;
    makeRelations();
    makeTuples();
}

void Interpreter::makeRelations() {
    for(Predicate* s : datalogProgram.getSchemes()){
        Header *h = new Header();
        for(int i = 0; i < s->getParamas().size(); i++){
            h->addAttributes(s->getParamas().at(i)->toString());
        }
        Relation* r = new Relation(s->getID(), h);
        database.add(s->getID(), r);
    }
}

void Interpreter::makeTuples() {
    for(Predicate* f : datalogProgram.getFacts()){
        Tuple t = Tuple();
        for(int i = 0; i < f->getParamas().size(); i++){
            t.addValue(f->getParamas().at(i)->toString());
        }
        database.at(f->getID())->addTuple(t);
    }
}

//Relation *Interpreter::evalutePredicate(Predicate &p) {

//}


//
// Created by Gideon Tonkinson on 10/26/21.
//

#include "Interpreter.h"

Interpreter::Interpreter(DatalogProgram* datalogProgram) {
    this->datalogProgram = datalogProgram;
    makeRelations();
    makeTuples();
    graph = new Graph(datalogProgram->getRules());
    rGraph = graph->populateGraph();
    graph->toString();
    evaluateRules();
    evaluateQueries();
}

void Interpreter::makeRelations() {
    for(Predicate* s : datalogProgram->getSchemes()){
        Header *h = new Header();
        for(size_t i = 0; i < s->getParamas().size(); i++){
            h->addAttributes(s->getParamas().at(i)->toString());
        }
        auto* r = new Relation(s->getID(), h);
        database.add(s->getID(), r);
    }
}

void Interpreter::makeTuples() {
    for(Predicate* f : datalogProgram->getFacts()){
        Tuple t;
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

void Interpreter::evaluateRule(Rule* rule) {
    Relation* r  = evaluatePredicate(rule->getBodyPreds().at(0));
    for(size_t i = 1; i < rule->getBodyPreds().size(); i++){
        r = r->join(evaluatePredicate(rule->getBodyPreds().at(i)));
    }
    std::vector<size_t> indices;
    for(Parameter* p : rule->getHeadPred()->getParamas()){
        for(size_t i = 0; i < r->getHeader()->getAttributes().size(); i++){
            if(r->getHeader()->getAttributes().at(i) == p->toString()){
                indices.push_back(i);
            }
        }
    }
    r = r->project(indices);
    std::vector<std::string> names;
    for(std::string s : database.at(rule->getHeadPred()->getID())->getHeader()->getAttributes()){
        names.push_back(s);
    }
    r = r->rename(names);
    std::cout << database.at(rule->getHeadPred()->getID())->unite(r);
}

void Interpreter::evaluateRules() {
    std::cout << "Rule Evaluation\n";
    for(size_t i = 0; i < graph->getSCCs().size(); i++){
        size_t numTuples;
        size_t numTuplesAfter;
        size_t numTimesThrough = 0;
        std::cout << "SCC: ";
        SCCToString(i);
        if(!graph->selfLoop(i)){
            for (size_t scc: *graph->getSCCs().at(i)) {
                Rule *rule = datalogProgram->getRules().at(scc);
                std::cout << rule->toString() << "\n";
                evaluateRule(rule);
            }
            numTimesThrough++;
        } else {
            do {
                numTuples = database.size();
                for (size_t scc: *graph->getSCCs().at(i)) {
                    Rule *rule = datalogProgram->getRules().at(scc);
                    std::cout << rule->toString() << "\n";
                    evaluateRule(rule);
                }
                numTuplesAfter = database.size();
                numTimesThrough++;
            } while (numTuplesAfter != numTuples);
        }
        std::cout << numTimesThrough << " passes: ";
        SCCToString(i);
    }
}

void Interpreter::evaluateQueries() {
    std::cout << "\nQuery Evaluation\n";
    for(Predicate* p : datalogProgram->getQueries()){
        Relation* r = evaluatePredicate(p);
        std::cout << p->toString() << "? ";
        if(r->numRows() > 0) {
            std::cout << "Yes(" << r->numRows() << ")\n";
        } else {
            std::cout << "No\n";
        }
        std::cout << r->toString();
    }
}

void Interpreter::SCCToString(size_t i) {
    std::stringstream ss;
    std::set<size_t>* scc = graph->getSCCs().at(i);
    for(auto it = scc->begin(); it != scc->end(); it++) {
        ss << "R" << *it << ",";
    }
    ss.seekp(-1, std::ios_base::end); //remove extra comma?
    ss << "\n";
    std::cout << ss.str();
}



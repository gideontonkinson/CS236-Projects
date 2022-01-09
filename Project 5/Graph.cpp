//
// Created by Gideon Tonkinson on 12/6/21.
//

#include "Graph.h"

Graph::Graph(std::vector<Rule *> nodeList) {
    nodes = nodeList;
    for(size_t i = 0; i < nodes.size(); i++){
        std::set<int> edges;
        dependencies.insert({i, edges});
    }
}

/**Populates the graph with edges and identifies the SCCs**/
Graph* Graph::populateGraph() {
    Graph* rGraph = new Graph(nodes);
    int i = 0;
    for(auto currNode : nodes){
        for(auto pred: currNode->getBodyPreds()){
            int j = 0;
            for(auto n : nodes){
                if (n->getHeadPred()->getID() == pred->getID()){
                    addEdge(i,j);
                    rGraph->addEdge(j,i);
                }
                j++;
            }
        }
        i++;
    }
    rGraph->dfsForestPost();
    for(auto it = rGraph->postOrder.rbegin(); it != rGraph->postOrder.rend(); it++) {
        postOrder.push_back(*it);
    }
    dfsSCCForest();
    return rGraph;
}

/**Adds edges to the graph**/
void Graph::addEdge(int i, int j) {
    if(dependencies.find(i) != dependencies.end()){
        dependencies.find(i)->second.insert(j);
    }
}

/**Does a dfs search on the graoh and returns a tree as a set**/
void Graph::dfsPost(size_t i) {
    auto edges = dependencies.find(i)->second;
    std::set<int>::iterator it = edges.begin();
    while(it != edges.end()) {
        if(!nodes.at(*it)->isVisited()){
            nodes.at(*it)->visit();
            dfsPost(*it);
            postOrder.push_back(*it);
        }
        it++;
    }
}


void Graph::dfsForestPost(){
    for(auto node : nodes){
        node->unvisit();
    }
    for(size_t i = 0; i < nodes.size(); i++) {
        if (!nodes.at(i)->isVisited()) {
            nodes.at(i)->visit();
            dfsPost(i);
            postOrder.push_back(i);
        }
    }
}

std::set<size_t>* Graph::dfsSCC(size_t i) {
    std::set<size_t>* tree = new std::set<size_t>;
    auto edges = dependencies.find(i)->second;
    std::set<int>::iterator it = edges.begin();
    while(it != edges.end() && !edges.empty()) {
        if(!nodes.at(*it)->isVisited()){
            nodes.at(*it)->visit();
            std::set<size_t>* temp = dfsSCC(*it);
            tree->insert(temp->begin(), temp->end());
        }
        it++;
    }
    tree->insert(i);
    return tree;
}

void Graph::dfsSCCForest() {
    for(auto node : nodes){
        node->unvisit();
    }
    for(size_t i = 0; i < postOrder.size(); i++){
        size_t temp = postOrder.at(i);
        if (!nodes.at(temp)->isVisited()) {
            nodes.at(temp)->visit();
            SCCs.push_back(dfsSCC(temp));
        }
    }
}

std::vector<std::set<size_t> *> Graph::getSCCs() {
    return SCCs;
}

bool Graph::selfLoop(size_t i) {
    bool out = false;
    if(SCCs.at(i)->size() > 1)
        return true;
    for(size_t r : *SCCs.at(i)){
        if(dependencies.find(r)->second.find(r) != dependencies.find(r)->second.end()){
            return true;
        }
    }
    return out;
}

void Graph::toString() {
    std::stringstream ss;
    ss << "Dependency Graph\n";
    for(size_t i = 0; i < nodes.size(); i++){
        ss << "R" << i << ":";
        for(auto r : dependencies.find(i)->second) {
            ss << "R" << r << ",";
        }
        if(!dependencies.find(i)->second.empty()) {
            ss.seekp(-1, std::ios_base::end); //remove extra comma?
        }
        ss << "\n";
    }
    ss << "\n";
    std::cout << ss.str();
}
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
    for(size_t i = 0; i < nodes.size(); i++){
        for(size_t j = 0; j < nodes.at(i)->getBodyPreds().size(); j++){
            for(auto n : nodes){
                if (n->getHeadPred()->getID() == nodes.at(i)->getBodyPreds().at(j)->getID()){
                    addEdge(i,j);
                    rGraph->addEdge(j,i);
                }
            }
        }
    }
    rGraph->dfsForestPost();
    postOrder = rGraph->postOrder;
    dfsSCCs();
    return rGraph;
}

/**Adds edges to the graph**/
void Graph::addEdge(int i, int j) {
    if(dependencies.find(i) != dependencies.end()){
        dependencies.find(i)->second.insert(j);
    }
}

/**Does a dfs search on the graoh and returns a tree as a set**/
std::set<size_t>* Graph::dfs(size_t i) {
    std::set<size_t>* tree = new std::set<size_t>;
    auto edges = dependencies.find(i)->second;
    std::set<int>::iterator it = edges.begin();
    for(size_t j = 0; j < edges.size(); j++){
        while(it != edges.end()) {
            if(!nodes.at(*it)->isVisited()){
                nodes.at(*it)->visit();
                std::set<size_t>* temp = dfs(*it);
                tree->insert(temp->begin(), temp->end());
                postOrder.push_back(i);
            }
            it++;
        }
    }
    tree->insert(i);
    return tree;
}

void Graph::dfsForestPost(){
    for(auto node : nodes){
        node->unvisit();
    }
    for(size_t i = 0; i < nodes.size(); i++) {
        if (!nodes.at(i)->isVisited()) {
            nodes.at(i)->visit();
            dfs(i);
        }
    }
}

void Graph::dfsSCCs() {
    for(auto node : nodes){
        node->unvisit();
    }
    for(size_t i = postOrder.size()-1; i > -1; i--) {
        if (!nodes.at(postOrder.at(i))->isVisited()) {
            nodes.at(i)->visit();
            SCCs.push_back(dfs(postOrder.at(i)));
        }
    }
}

std::vector<std::set<size_t> *> Graph::getSCCs() {
    return SCCs;
}

bool Graph::selfLoop(size_t i) {
    if(dependencies.find(i)->second.find(i) == dependencies.find(i)->second.end()){
        return false;
    } else {
        return true;
    }
}

std::string Graph::toString() {
    std::string out = "Dependency Graph\n";
    for(int i = 0; i < nodes.size(); i++){
        out += &"R" [ i];
        out += ":";
        for(auto r : dependencies.find(i)->second){
            out += &"R" [ r];
        }
        if(i != dependencies.find(i)->second.size()-1){
            out += ",";
        } else {
            out += "\n";
        }
    }
    out += "\n";
    return out;
}
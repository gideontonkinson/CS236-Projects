//
// Created by Gideon Tonkinson on 12/6/21.
//

#ifndef PROJECT_5_GRAPH_H
#define PROJECT_5_GRAPH_H
#include <map>
#include <set>
#include <vector>
#include <stack>
#include <iostream>
#include <sstream>
#include "Rule.h"

class Graph {
private:
    std::map<int, std::set<int>> dependencies;
    std::vector<Rule*> nodes;
    std::vector<std::set<size_t>*> SCCs;
    std::vector<size_t> postOrder;
    void addEdge(int i, int j);
    void dfsPost(size_t);
    void dfsForestPost();
    std::set<size_t>* dfsSCC(size_t i);
    void dfsSCCForest();
public:
    Graph(std::vector<Rule*> nodeList);
    Graph* populateGraph();
    std::vector<std::set<size_t>*> getSCCs();
    void toString();
    bool selfLoop(size_t i);
};


#endif //PROJECT_5_GRAPH_H

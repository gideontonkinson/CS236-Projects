//
// Created by Gideon Tonkinson on 12/6/21.
//

#ifndef PROJECT_5_GRAPH_H
#define PROJECT_5_GRAPH_H
#include <map>
#include <set>
#include <vector>
#include <stack>
#include "Rule.h"

class Graph {
private:
    std::map<int, std::set<int>> dependencies;
    std::vector<Rule*> nodes;
    std::vector<std::set<size_t>*> SCCs;
    std::vector<size_t> postOrder;
    void addEdge(int i, int j);
    std::set<size_t>* dfs(size_t);
    void dfsForestPost();
    void dfsSCCs();
public:
    Graph(std::vector<Rule*> nodeList);
    Graph* populateGraph();
    std::vector<std::set<size_t>*> getSCCs();
    std::string toString();
    bool selfLoop(size_t i);
};


#endif //PROJECT_5_GRAPH_H

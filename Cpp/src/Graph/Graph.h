// Graph.h
#ifndef GRAPH_H
#define GRAPH_H

#include <vector>

class Graph {
public:
    Graph();
    Graph(int v);
    void AddEdge(int s, int t);
    std::vector<int> BreadthFirstSearch(int s, int t);
    std::vector<int> DepthFirstSearch(int s, int t);
    

private:
    int v;
    std::vector<std::vector<int>> adj;
    std::vector<int> GetOrder(const std::vector<int>& q, int t);
    void DFSHelper(int s, int t, std::vector<bool>& visited, std::vector<int>& prev);
};

#endif // GRAPH_H
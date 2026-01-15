// Graph.h
#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <string>

class Graph {
public:
    Graph();
    Graph(int v);
    void AddEdge(int s, int t);
    std::vector<int> BreadthFirstSearch(int s, int t);
    std::vector<int> DepthFirstSearch(int s, int t);
    static bool ExistWord(const std::vector<std::vector<char>>& board, const std::string& word);
    

private:
    int v;
    std::vector<std::vector<int>> adj;
    std::vector<int> GetOrder(const std::vector<int>& q, int t);
    void DFSHelper(int s, int t, std::vector<bool>& visited, std::vector<int>& prev);
    static bool CheckSubWord(const std::vector<std::vector<char>>& board, const std::string& word, std::vector<std::vector<bool>>& visited, int i, int j, int k);
};

#endif // GRAPH_H
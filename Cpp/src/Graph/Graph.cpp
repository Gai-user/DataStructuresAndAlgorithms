#include <vector>
#include <queue>
#include <algorithm>
#include "Graph.h"

Graph::Graph() : v(0), adj(0) {}
Graph::Graph(int v) : v(v), adj(v) {}

void Graph::AddEdge(int s, int t) {
    adj[s].push_back(t);
    adj[t].push_back(s);
}

std::vector<int> Graph::GetOrder(const std::vector<int>& prev, int t) {
    std::vector<int> path;
    for (int i = t; i != -1; i = prev[i]) {
        path.push_back(i);
    }
    std::reverse(path.begin(), path.end());
    return path;
}


std::vector<int> Graph::BreadthFirstSearch(int s, int t)
{
    if (s == t) {
        return {};
    }
    std::vector<bool> visited(v, false);
    std::vector<int> prev(v, -1);
    std::queue<int> q;

    q.push(s);
    visited[s] = true;

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        for (int next : adj[cur]) {
            if (visited[next]) {
                continue;
            }
            prev[next] = cur;
            if (next == t) {
                return GetOrder(prev, t);
            }
            q.push(next);
            visited[next] = true;
        }
    }
    return {};
    
}
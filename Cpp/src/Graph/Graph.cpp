#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <iostream>
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

void Graph::DFSHelper(int s, int t, std::vector<bool>& visited, std::vector<int>& prev)
{
    if (s == t) {
        return;
    }
    visited[s] = true;
    for (const auto& cur : adj[s]) {
        if (visited[cur]) {
            continue;
        }
        prev[cur] = s;
        DFSHelper(cur, t, visited, prev);
    }
}

std::vector<int> Graph::DepthFirstSearch(int s, int t)
{
    if (s == t) {
        return {};
    }

    std::vector<bool> visited(v, false);
    std::vector<int> prev(v, -1);
    DFSHelper(s, t, visited, prev);
    return GetOrder(prev, t);
}

/**
 * 单词搜索，单词word是否存在于二维网格中
 * @param board 二维向量
 * @param word 字符串 
 */
bool Graph::ExistWord(const std::vector<std::vector<char>>& board, const std::string& word) 
{
    if (board.empty() || word.empty()) {
        return false;
    }
    int row = board.size();
    int col = board[0].size();
    std::vector<std::vector<bool>> visited(row, std::vector<bool>(col, false));
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (CheckSubWord(board, word, visited, i, j, 0)) {
                return true;
            }
        }
    }
    return false;
}

/**
 * 判断在二维网格(i, j)处，是否可以找到word[k:]
 * 如果board[i,j] != word[k]，返回false
 * 如果k是word的最后一个单词，且于board[i,j]相同，返回ture
 * 否则，从(i, j)开始搜索，是否可以组成word[k+1:]
 */
bool Graph::CheckSubWord(const std::vector<std::vector<char>>& board, const std::string& word, std::vector<std::vector<bool>>& visited, int i, int j, int k)
{   
    if (board[i][j] != word[k]) {
        return false;
    } else if (k == word.size() - 1) {
        return true;
    }
    std::vector<std::vector<int>> directions{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    visited[i][j] = true;
    for (const auto& dir : directions) {
        int curI = i + dir[0];
        int curJ = j + dir[1];

        if (curI < 0 || curI >= board.size() || curJ < 0 || curJ >= board[0].size()) {
            continue;
        }
        if (visited[curI][curJ]) {
            continue;
        }
        if (CheckSubWord(board, word, visited, curI, curJ, k+1)) {
            return true;
        }
    }
    visited[i][j] = false;
    return false;
}
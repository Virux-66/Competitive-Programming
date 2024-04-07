#include <bits/stdc++.h>

/**
 * Algorithm: Topological Sort
 * Type: Graph
 * Statement: A topological sort or topological ordering of
 * a directed graph is a linear ordering of its vertices 
 * such that for every directed ege (u, v) from vertex u
 * to vertex v, u comes before v in the ordering.
 * A topological ordering is possible if and only if the graph
 * has no directed cycles, that is, it's a directed ascyclic graph(DAG).
 */

std::vector<int> result;
std::vector<bool> visited;
std::set<int> path;
bool acyclic = false;

void dfs(int node, const std::vector<std::vector<std::pair<int, int>>>& graph){
    if(visited[node]){
        return;
    }
    visited[node] = true;
    path.insert(node);
    for(int i = 0; i < graph[node].size(); ++i){
        auto end = graph[node][i].first;
        if(path.find(end) != path.end()){
            acyclic = true;
        }
        dfs(end, graph);
    } 
    path.erase(node);
    result.push_back(node);
}

std::vector<int> topological_sort(int n, std::vector<std::vector<std::pair<int, int>>> graph){
    visited = std::vector<bool>(n, false);
    for(int i = 0; i < n; ++i){
        dfs(i, graph);
    }
    if(acyclic){
        return {};
    }
    std::reverse(result.begin(), result.end());
    return result;
}
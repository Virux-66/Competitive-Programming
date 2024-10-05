#include <bits/stdc++.h>

/**
 * Algorithm: Bellman-Ford algorithm
 * Type: DP, graph
 * Statement: For finding a single source vertex to all of 
 * the other vertices in a weight (un)digraph.
 * The difference from Dijkstra algorithm is that Bellman-Ford algorithm
 * allows negative edge weight while Dijkstra not. 
 * This algorithms doesn't allow negative cycle (i.e. a cycle whose edges sum to a negative value)
 * However, it's slower than Dijkstra algorithm.
 * Time Complexity: O(|V|*|E|)
*/
// pesudo-code
std::vector<int> BellmanFord(std::vector<std::vector<int>> edges, int n, int start){
    std::vector<std::vector<std::pair<int, int>>> graph(n, std::vector<std::pair<int, int>>());
    std::vector<int> dist(n, INT_MAX);
    
    for(int i = 0; i < edges.size(); i++){
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];
        graph[u].push_back({v, w});
    }

    dist[start] = 0;

    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < graph[j].size(); k++){
                int u = j;
                int v = graph[j][k].first;
                int w = graph[j][k].second;
                if(dist[u] != INT_MAX){
                    dist[v] = std::min(dist[v], dist[u] + w);
                }
            }
        }
    }
    return dist;
}

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
std::vector<int> BellmanFord(std::vector<int> vertices, std::vector<std::pair<std::pair<int, int>,int>> edges, int source){
    int n = vertices.size();
    std::vector<int> distance(n, INT_MAX);
    std::vector<int> predecessor(n, -1);
    
    distance[source] = 0;
    for(int i = 0; i < n - 1; i++){
        // For each round, relax every edge
        for(auto edge: edges){
            int u = edge.first.first;
            int v = edge.first.second;
            int w = edge.second;
            if(distance[u] + w < distance[v]){
                distance[v] = distance[u] + w;
                predecessor[v] = u;
            }
        }
    }
    return distance;
}
#include <bits/stdc++.h>

/**
 * Algorithm: Dijsktra
 * Time Complexity: O(|E| + |V|log|V|)
 */

std::vector<int> Dijkstra(std::vector<std::vector<int>> edges, int n, int start){
    // edges = {[start1, end1, weight1], ... , {startn, endn, weightn}}    

    std::vector<std::vector<std::pair<int, int>>> graph(n, std::vector<std::pair<int, int>>());
    std::vector<int> dist(n, INT_MAX);
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
    std::vector<bool> visited(n, false);

    // build graph into linked table.
    for(int i = 0; i < edges.size(); i++){
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];
        graph[u].push_back({v, w});
    }
    dist[start] = 0;
    pq.push({dist[start], start});

    while(!pq.empty()){
        auto pr = pq.top();
        pq.pop();
        int u = pr.second;
        /** The node that has been pq is also possible to have been visited.
         *  This if statement can reduces much time overhead.
         */
        if(visited[u]){
            continue;
        }
        for(int i = 0; i < graph[u].size(); i++){
            int v = graph[u][i].first;
            int w = graph[u][i].second;
            if(visited[v]){
                continue;
            }
            dist[v] = std::min(dist[v], pr.first + w);
            pq.push({dist[v], v});
        }
        visited[u] = true;
    }
    return dist;
}
#include <bits/stdc++.h>

/**
 * Algorithm: minimum spanning tree - Prim algorithm
 * Note: For each iteration of selecting edge, it's ok that the vertexs
 * of this edge are not at the same set. But for Prim algorithm,
 * for eac iteration of selecting edge, the edge must be connecting
 * the selected set and unselected set.
 */
class comparator{
    public:
        bool operator()(std::vector<int>& vec1, std::vector<int>& vec2){
            return vec1[2] >= vec2[2];
        }
};

int prim(std::vector<std::vector<int>> edges, int n){
    std::vector<std::vector<std::pair<int, int>>> graph(n);
    std::priority_queue<std::vector<int>, std::vector<std::vector<int>>, comparator> pq;
    std::vector<bool> selected(n, false);
    int cost = 0;
    int vertex_count = 0;

    for(int i = 0; i < edges.size(); i++){
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    selected[0] = true;
    for(int i = 0; i < graph[0].size(); i++){
        int v = graph[0][i].first;
        int w = graph[0][i].second;
        pq.push({0, v, w});
    }
    ++vertex_count;

    while(vertex_count != n){
        std::vector<int> e = pq.top();
        pq.pop();
        int u = e[0];
        int v = e[1];
        int w = e[2];
        if(selected[u] ^ selected[v]){
            cost += w;
            int new_vertex = selected[u]? v:u;
            selected[new_vertex] = true;
            ++vertex_count;
            for(int i = 0; i < graph[new_vertex].size(); i++){
                int u_ = new_vertex;
                int v_ = graph[new_vertex][i].first;
                int w_ = graph[new_vertex][i].second;
                if(selected[u_] ^ selected[v_]){
                    pq.push({u_, v_, w_});
                }
            }
        }
    }
    return cost;
}


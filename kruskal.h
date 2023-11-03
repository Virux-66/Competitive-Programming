#include <bits/stdc++.h>

/**
 * Algorithm: minimum spanning tree - Kruskal algorithm(based on DSU)
 * Time Complexity: O(|E|log|E| + |V|)
 * Note: For each iteration of selecting edge, it's ok that the vertexs
 * of this edge are not at the same set. But for Prim algorithm,
 * for eac iteration of selecting edge, the edge must be connecting
 * the selected set and unselected set.
 */
class Dsu{
    public:
        std::vector<int> parents;
        std::vector<int> sizes;
        Dsu(int n){
            parents = std::vector<int>(n);
            sizes = std::vector<int>(n, 1);
            for(int i = 0; i < n; i++){
                parents[i] = i;
            }
        }

        void union_set(int u, int v){
            int pu = find_set(u);
            int pv = find_set(v);
            if(pu != pv){
                if(sizes[pu] <= sizes[pv]){
                    parents[pv] = pu;
                    sizes[pu] += sizes[pv];
                }else{
                    parents[pu] = pv;
                    sizes[pu] += sizes[pv];
                }
            }
        }

        int find_set(int u){
            if(parents[u] == u){
                return u;
            }
            return parents[u] = find_set(parents[u]);
        }
};

class comparator{
    public:
        bool operator()(std::vector<int>& vec1, std::vector<int>& vec2){
            return vec1[2] <= vec2[2];
        }
};


int Kruskal(std::vector<std::vector<int>> edges, int n){
    // edges = {[u1, v1, w1], ...}
    int cost = 0;
    int edge_num = 0;
    Dsu d(n);
    std::sort(edges.begin(), edges.end(), comparator());
    
    for(int i = 0; i < edges.size(); i++){
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];
        if(d.find_set(u) != d.find_set(v)){
            cost += w;
            d.union_set(u, v);
            if(++edge_num >= n - 1){
                break;
            }
        }
    }
    return cost;
}
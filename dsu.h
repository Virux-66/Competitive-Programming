#include<bits/stdc++.h>

/**
 * Data structure: disjoint Set Union(DSU)
 * Detail: DSU used to verify whether two value is within the same set.
 * 		   If we combine both optimizations-path compression with union by size
 *         we will reach nearly constant time queries(find_set). It turns out
 * 		   the final amortized time complexity is O(a(n)), where a(n) is the  
 *         inverse Ackermann function, which grows so slowly, that it doesn't
 *         exceed 4 for all reasonable n.
*/

class dsu{
    public:
        std::vector<int> parents;        
        std::vector<int> size;
        dsu(int n){
            parents=std::vector<int>(n);
            size=std::vector<int>(n);
            for(int i=0; i<n; i++){
                parents[i] = i;
                size[i] = 1;
            }
        }
        int find_set(int v){
            if(parents[v] == v){
                return v;
            }
            return parents[v] = find_set(parents[v]);
        }
        void union_set(int a, int b){
            int pa = find_set(a);
            int pb = find_set(b);
            if(pa != pb){
                if(size[pa] < size[pb]){
                    std::swap(pa,pb);
                }
                parents[pb]=pa;
                size[pa] += size[pb];
            }
        }
};
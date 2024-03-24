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

class Dsu{
    public:
        std::vector<int> parents;        
        std::vector<int> size;
        Dsu(int n){
            parents = std::vector<int>(n);
            size = std::vector<int>(n);
            for(int i = 0; i < n; i++){
                parents[i] = i;
                size[i] = 1;
            }
        }
        int FindSet(int v){
            if(parents[v] == v){
                return v;
            }
            return parents[v] = FindSet(parents[v]);
        }
        void UnionSet(int a, int b){
            int pa = FindSet(a);
            int pb = FindSet(b);
            if(pa != pb){
                if(size[pa] < size[pb]){
                    std::swap(pa,pb);
                }
                parents[pb] = pa;
                size[pa] += size[pb];
            }
        }
};
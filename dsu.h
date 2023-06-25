#include<bits/stdc++.h>
using namespace std;

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
        vector<int> parents;        
        vector<int> size;
        dsu(vector<int>& vec){
            int n=vec.size();
            parents=vector<int>(n);
            size=vector<int>(n);
            for(int i=0; i<n; i++){
                parents[i]=i;
                size[i]=1;
            }
        }
        int find_set(int v){
            if(parents[v]==v){
                return v;
            }
            return parents[v]=find_set(parents[v]);
        }
        void union_set(int a, int b){
            int pa=find_set(a);
            int pb=find_set(b);
            if(pa != pb){
                if(size[pa] < size[pb]){
                    swap(pa,pb);
                }
                parents[pb]=pa;
                size[pa]+=size[pb];
            }
        }
};
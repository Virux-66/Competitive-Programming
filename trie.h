#include<bits/stdc++.h>
using namespace std;
/* Data structure: Trie
 * Detail:Formally a Trie is a rooted tree, where each edge of the tree is labeled 
 * 		by a letter. All outgoing edge from one vertex must have different labels.
 * 		Consider any path in the Trie from the root to any vertex. If we write out the
 * 		labels of all edges on the path, we get a string that corresponds to this path.
 * 		For any vertex in the trie we will associate the string from the root to vertex.
 * Complexity: m string with k length, O(mk) 
 */

#define K 26
class vertex{
	public:
		int next[K];
		bool leaf=false;
		vertex(){
			fill(begin(next), end(next), -1);
		}
};


class trie{
	public:
		vector<vertex> tree;
		void add_string(string const& s){
			int v=0;
			for(char ch:s){
				int c=ch-'a';
				if(tree[v].next[c] == -1){
					tree[v].next[c]=tree.size();
					tree.emplace_back();
				}
				v=tree[v].next[c];
			}
			tree[v].leaf=true;
		}
};

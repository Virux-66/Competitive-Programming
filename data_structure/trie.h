#include<bits/stdc++.h>
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
		std::vector<int> next;
		bool leaf = false;
		vertex(): next(K, -1){}
};


class Trie{
	public:
		std::vector<vertex> tree_;
		Trie(){
			tree_ = std::vector<vertex>(1);
		}
		void AddString(const std::string& s){
			int v = 0;
			for(char ch : s){
				int c = ch - 'a';
				if(tree_[v].next[c] == -1){
					tree_[v].next[c] = tree_.size();
					tree_.emplace_back();
				}
				v = tree_[v].next[c];
			}
			tree_[v].leaf=true;
		}

		bool FindString(const std::string& s){
			int v = 0;
			for(auto ch : s){
				int c = ch - 'a';
				if(tree_[v].next[c] != -1){
					v = tree_[v].next[c];
				}else{
					v = 0;
					break;
				}
			}
			return tree_[v].leaf;
		}
};
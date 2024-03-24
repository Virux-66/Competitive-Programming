#include<bits/stdc++.h>
/* Data structure: Sparse table
 * Detail:	Sparse table can answer most range queries in O(log n), but its true power
 * 			is answring range minimum queries (or equivalent range maximum queries).
 * 			For those queries, it can compute the answer in O(1) time.
 * Intuition: Any non-negative number can be uniquely represented as a sum of
 * 			  descreasing power of two. E.g. 13 = (1101)2 = 8 + 4 + 1.
 * 			  For a number x, there can be most upper(log x) summands. By the same
 * 			  reasoning any interval can be uniquely represented as a union of
 * 			  intervals with lengths that are decreasing powers of two.
 * 			  E.g. [2,14] = [2,9] U [10,13] U [14,14]
 * Complexity: building sparse table, O(NlogN), each query O(1)
 * array[N] : inital array
 * st :  st[i][j] store the answer for the range [j, j+2^i-1]
 */

template <typename T, typename Func>
class SparseTable{
	public:
		SparseTable(std::vector<T>& vec){
			int n = vec.size();
			int k = (int)std::log2(n);			
			st_ = std::vector<std::vector<T>>(k+1, std::vector<T>(n));

			for(int i = 0; i < n; i++){
				st_[0][i] = vec[i];
			}

			for(int i = 1; i < st_.size(); i++){
				for(int j = 0; j + (1 << i) <= n; j++){
					st_[i][j] = functor(st_[i-1][j], st_[i-1][j + (1 << (i-1))]);
				}
			}
		}

		T query(int i, int j){
			int dist = j - i + 1;
			int log_dist = int(std::log2(dist));
			return functor(st_[log_dist][i], st_[log_dist][i + dist - int(std::pow(2, log_dist))]);
		}
		
		std::vector<std::vector<T>> st_;
		Func functor_;

};

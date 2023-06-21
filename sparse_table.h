#include<bits/stdc++.h>
using namespace std;
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

class sparse_table{
	public:
		vector<vector<int>> st;
		sparse_table(vector<int>& vec){
			int N = vec.size();
			int K = log2(N);			
			st = vector<vector<int>>(K+1, vector<int>(N));
			copy(vec.begin(), vec.end(), st[0]);
			for(int i=1; i<K+1; i++){
				for(int j=0; j+(1<<i)<=N; j++){
					st[i][j]=min(st[i-1][j],st[i-1][j+(1<<(i-1))]);
				}
			}
		}

		int query(int i, int j){
			int dist = j-i+1;
			int log_dist = int(log2(dist));
			return min(st[log_dist][i], st[log_dist][i+dist-int(pow(2,log_dist))]);
		}
};

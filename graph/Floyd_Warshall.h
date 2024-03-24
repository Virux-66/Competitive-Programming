#include <bits/stdc++.h>

/**
 * Algorithms: Floyd_Warshall algorithm
 * Type: DP, graph
 * Statement: Find shortest paths in directed weighted graph with positive
 * or negtive edge weights(but no negative) cycles.
 * Detail: Consider a graph G with vertices V numbered 1 through N.
 * Further consider a function shortestPath(i, j, k) that returns the length of 
 * the shortest possible path (if one exists) from i to j using the previous k vertex as intermediate points along the way.
 * By definition, this is the value shortestPath(i, j, N), whihc we will find recursively.
 * Observe that shortestPath(i, j, k) must be less that or equal to shorestPath(i, j, k - 1):
 * we have more flexibility if we are allowed to use the vertex k. If shortestPath(i, j, k) 
 * is in fact less than shortestPath(i, j, k - 1), then there must be a path from i to j
 * using vertics {1, 2, ..., k} that is shortest than any such path that does not use
 * the vertex k. This path can be decomposed as:
 * (1) a path from i to k that uses the vertics {1, 2, ..., k - 1}, followed by
 * (2) a path from k to j that uses the vertices {1, 2, ..., k - 1}. 
 * shortestPath(i, j, k) = min(shortestPath(i, j, k - 1), shortestPath(i, k, k - 1) + shortestPath(k, j, k - 1))
 * basecase: shortestPath(i, j, 0) = w(i, j)
 * Time Complexity: O(V^3)
*/
void shortest_distance(std::vector<std::vector<int>>&matrix){
    // Code here
    int n = matrix.size();
    std::vector<std::vector<std::vector<int>>> dp(n+1, std::vector<std::vector<int>>(n, std::vector<int>(n, 0)));
    dp[0] = matrix;
    
    for(int k = 1; k <= n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(dp[k-1][i][k-1] != -1 && dp[k-1][k-1][j] != -1){
                    int tmp = dp[k-1][i][k-1] + dp[k-1][k-1][j];
                    if(dp[k-1][i][j] != -1){
                        dp[k][i][j] = std::min(dp[k-1][i][j], dp[k-1][i][k-1] + dp[k-1][k-1][j]);
                    }else{
                        dp[k][i][j] = dp[k-1][i][k-1] + dp[k-1][k-1][j];
                    }
                }else{
                    dp[k][i][j] = dp[k-1][i][j];
                }        
            }
        }
    }
    matrix = dp[n];
}

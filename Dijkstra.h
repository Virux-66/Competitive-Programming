#include <bits/stdc++.h>

/**
 * Algorithm: minimum cost path
 * Type: DP, Graph, Dijkstra
 * Statement: Given a square grid of size N, each cell of which contains integer cost 
 * which represents a cost to traverse through that cell, 
 * we need to find a path from top left cell to bottom right cell 
 * by which the total cost incurred is minimum From the cell (i,j) 
 * we can go (i,j-1), (i, j+1), (i-1, j), (i+1, j). 
 * Solution: Dijkstra shortest path algorithm.
*/

// Not optimal, TLE
int minimumCostPath(std::vector<std::vector<int>>& grid) 
{
    int n = grid.size();
    std::priority_queue<std::pair<int,int>, std::vector<std::pair<int,int>>, std::greater<std::pair<int,int>>> pq;
    std::vector<std::vector<int>> dp(n, std::vector<int>(n ,INT_MAX));
    std::vector<std::vector<bool>> visited(n, std::vector<bool>(n, false));
    dp[0][0] = grid[0][0];

    pq.push(std::make_pair(dp[0][0], 0));

    while(!pq.empty()){
        auto val = pq.top();
        pq.pop();
        int i = val.second / n;
        int j = val.second % n;
        // The same node might be pushed to priority queue more than one.
        if(!visited[i][j]){
            if(i - 1 >= 0 && !visited[i - 1][j]){
                int tmp = dp[i][j] + grid[i - 1][j];
                dp[i - 1][j] = std::min(dp[i - 1][j], tmp);
                pq.push(std::make_pair(dp[i - 1][j], (i - 1)*n + j));
            }
            if(i + 1 < n && !visited[i + 1][j]){
                int tmp = dp[i][j] + grid[i + 1][j];
                dp[i + 1][j] = std::min(dp[i + 1][j], tmp);
                pq.push(std::make_pair(dp[i + 1][j], (i + 1)*n + j));
            }
            if(j - 1 >= 0 && !visited[i][j - 1]){
                int tmp = dp[i][j] + grid[i][j - 1];
                dp[i][j - 1] = std::min(dp[i][j - 1], tmp);
                pq.push(std::make_pair(dp[i][j - 1], i*n + (j - 1)));
            }
            if( j + 1 < n && !visited[i][j + 1]){
                int tmp = dp[i][j] + grid[i][j + 1];
                dp[i][j + 1] = std::min(dp[i][j + 1], tmp);
                pq.push(std::make_pair(dp[i][j + 1], i*n + (j + 1)));
            }
            visited[i][j] = true;
        }
    }
    return dp[n - 1][n - 1];
}   
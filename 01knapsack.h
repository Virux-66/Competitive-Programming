#include<bits/stdc++.h>

/**
 * Algorithm: 0-1 knapsack problem
 * Type: DP
 * Statement: You are given weights and values of N items, put these items
 * in a kanpsack of capacity W to get maximum total value in the knapsack.
 * Detail: Let dp[i][j] be with the first i items and j weight,
 * the maximum value. For each dp[i][j], we consider whether the item i-1
 * should be put in knapsack.
 * OJ: https://www.geeksforgeeks.org/0-1-knapsack-problem-dp-10/
*/

int kanpsack(int w, std::vector<int> weights, std::vector<int> values){
    int n = weights.size();
    std::vector<std::vector<int>> dp(n+1, std::vector<int>(w+1,0));
    for(int i=1; i<=n; i++){
        for(int j=1; j<=w; j++){
            if(j>=weights[i]){
                dp[i][j] = std::max(dp[i-1][j],values[i-1] + dp[i-1][j-weights[i-1]]);
                /**
                 * With duplicated items
                 * dp[i][j] = std::max(dp[i-1][j], values[i-1] + dp[i][j-weight[i-1]]);
                */
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][w];
}
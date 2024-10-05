#include<bits/stdc++.h>

/**
 * Algorithm: Rod cutting
 * Type: DP
 * Statement: Given a rod of length N inches and array of prices.
 * prices[i] denotes that value of a piece of length i.
 * Determine the maximum value obtainable by cutting up the rod.
 * OJ: https://www.geeksforgeeks.org/cutting-a-rod-dp-13/
*/

int rodCutting(std::vector<int> prices){
    int n = prices.size();
    std::vector<int> dp(n + 1, 0);
    dp[0] = 0;
    dp[1] = prices[0];
    for(int i = 2; i <= n; i++){
        for(int j = 1; j < i; j++){
            dp[i] = std::max(dp[i], std::max(dp[j] + dp[j - i], prices[i - 1]));
        }
    }
    return dp[n];
}
#include <bits/stdc++.h>

/**
 * Algorithm: Coin change problem
 * Type: DP
 * Statement: Given an integer array coins of size N representing different
 * denominations of currency and an integer sum, find the number of ways
 * you can make sum by using different combination from coins.
 * Assume that you have infinite supply of each type of coin.
 * And you can use any coins as many times as you want.
 * OJ: https://www.geeksforgeeks.org/coin-change-dp-7/
 * Solution: For a specific sum and a one of coins[i], you can choose either
 * include it or exclude it. In this case, for the find sum, we can generate
 * a recursive tree.
 *                              5 (1,2,3)
 *                          /                   \ 
 *                       2(1,2,3)              5(1,2)
 *                   /            \           /      \ 
 *                    -1(1,2,3)   2(1,2)   3(1,2)   5(1)
*/

long long count(int coins[], int N, int sum) {
    std::vector<std::vector<long long>> dp(sum + 1, std::vector<long long>(N, 0));
    for(int j = 0; j < N; j++){
        dp[0][j] = 1;
    }
    
    for(int i = 1; i <= sum; i++){
        if(i % coins[0] == 0){
            dp[i][0] = 1;
        }else{
            dp[i][0] = 0;
        }
    }
    
    for(int i = 1; i <= sum; i++){
        for(int j = 1; j < N; j++){
            if(coins[j] > i){
                dp[i][j] = dp[i][j-1];
            }else{
                dp[i][j] = dp[i][j-1] + dp[i - coins[j]][j];
            }
        }
    }
    return dp[sum][N-1];
}
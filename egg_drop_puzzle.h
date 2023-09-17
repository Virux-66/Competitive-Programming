#include <bits/stdc++.h>
/**
 * Algorithm: Egg drop puzzle
 * Type: DP
 * Statement: Suppose you have N eggs and you want to determine from which floors in a k-floor building 
 * you can drop an egg such that is doesn't break. 
 * You are to determine the minimum number of attempts you need in order find the critical floor in the worst case while using the best strategy.
 * Note: binary search is not the optimal solution. Let say we have 2 eggs and 100-floors building.
 * If we use binary search, the first floor we should try is 50-th floor. There are two possibilities: one of them is the egg dropped is not broken.
 * In this case, you can go upward to 75-th. 
 * The other case is the egg dropped is broken. In this case, for finding the first floor where one egg will be broken, you have to try from the first floor.
 * Since the floor might be 49-th floor, the number of trial is 50.
 * More optimal solution: Start with 14-th floor, with broken we should only check 1 to 13 leading to 14 trials at most. 
 * with non-broken, check 27-th floor. If egg in 27-th is broken, we only need to check 15 to 26(12 floors at most) 
 * which also causes 14 trials(trial(14) + trial(27) + trial(15 to 26)).
 * If egg in 27-th is not broken, then 39, 50, 60, 69, 77, 84, 90, 95, 99, 100.
 * 
 * Analysis: Let dp[n][k] be the minimal trials for n eggs and k floors. The recursive formulation is:
 * dp[n][k] = 1 + min(max(dp[n-1][i-1], dp[n][k - i])) i = 1 ... n
 * base case: dp[0][1...k] = INT_MAX
 *            dp[1][1...k] = k
 *            dp[1...n][0] = 0
*/

int eggDrop(int n, int k) 
{
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(k + 1, INT_MAX));
    for(int j = 1; j <= k; j++){
        dp[1][j] = j;
    }
    for(int i = 1; i <= n; i++){
        dp[i][0] = 0;
    }
    for(int i = 2; i <= n; i++){
        for(int j = 1; j <= k; j++){
            for(int z = 1; z <= j; z++){
                dp[i][j] = std::min(dp[i][j], 1 + std::max(dp[i-1][z - 1], dp[i][j - z]));
            }
        }
    }
    return dp[n][k];
}


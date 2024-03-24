#include <bits/stdc++.h>

/**
 * Algorithm: Painting the Fence
 * Type: DP
 * Statement: Given a fence with n posts and k colors, 
 * find out the number of ways of painting the fence 
 * so that not more than two consecutive posts have the same colors.
 * Detail:
 * Let T(n) be the total number of ways to paint n fence with kcolours, 
 * subject to the constraint that no three adjacent ports are the same.
 * Let D(n) be the number of ways to paint n fence with k colours, 
 * such that the last two fence are different colours
 * Let S(n) be the number of ways to paint n fence with k colours,
 * such that the last two fence are same colours.
 * Therefore, there are the following recurrence relations
 * D(n) = (k - 1)(D(n-1) + S(n-1))
 * S(n) = D(n-1)
 * T(n) = S(n) + D(n)
 * 
 * Combine the above three relation:
 * T(n) = (k - 1)(T(n-1) + T(n-2))
*/

long long paintFence(int n, int k){
    if(n == 0){
        return 1;
    }
    std::vector<long long> dp(n + 1, 0);
    dp[1] = k;
    dp[2] = k * k;
    for(int i = 3; i <= n; i++){
        dp[i] = ((k - 1) * (dp[i-1] + dp[i-2])) % int(1e9+7);
    }
    return dp[n];
}
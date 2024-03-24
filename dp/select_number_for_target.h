#include<bits/stdc++.h>

/**
 * Algorithm: the number of selecting some numbers for a specific sum in an unordered array.
 * Type: DP
 * Detail: Construct dp[n + 1][target + 1], the result is dp[n][target]
 */

int WaysOfSelecting(std::vector<int> nums, int target){
    int n = nums.size();
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(target + 1));    
    dp[0][0] = 1;
    for(int j = 1; j <= target; ++j){
        dp[0][j] = 0;
    }

    for(int i = 1; i <= n; ++i){
        for(int j = 0; j <= target; ++j){
            if(j >= nums[i - 1]){
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - nums[i - 1]];
            }else{
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][target];
}
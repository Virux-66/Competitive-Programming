#include <bits/stdc++.h>

/**
 * Algorithm: General climbing Staircase Problem 
 * Type: DP
 * Statement: Given an array of distinct integers nums and a target integer target, 
 * return the number of possible combinations that add up to target.
 */

int combinationSum4(std::vector<int>& nums, int target) {
  std::vector<unsigned long long> dp(target + 1, 0);
  dp[0] = 1;
  for(int i = 1; i <= target; ++i){
    for(auto x : nums){
      if(i >= x){
        dp[i] += dp[i - x];
      }
    }
  }
  return dp[target];
}
#include<bits/stdc++.h>

/**
 * Algorithm: Equal Subset Sum Partition Problem
 * Type: DP
 * Statement: Given an integer array nums, return true if you can partition
 * the array into two(or k) subsets such that the sum of the elements in both 
 * subsets is equal or false otherwise.
 * Detail: Let dp[i][j] be whether we can choose value from the first i elements 
 * such that their sum is equal to j.
 * OJ: https://leetcode.cn/problems/partition-equal-subset-sum/
*/

bool canPartition(std::vector<int>& nums) {
    int n = nums.size();
    int sum=0;
    for(int i=0; i<nums.size(); i++){
        sum += nums[i];
    }
    if(sum%2){
        return false;
    }
    std::vector<std::vector<int>> dp(n+1, std::vector<int>(sum/2+1,false));
    for(int i=1; i<n+1; i++){
        for(int j=1; j<sum/2+1; j++){
            if(nums[i-1] == j){
                dp[i][j]=true;
            }else{
                if(nums[i-1] < j){
                    dp[i][j] = (dp[i-1][j-nums[i-1]] | dp[i-1][j]);
                }else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
    }
    for(int i=0; i<n+1; i++){
        if(dp[i][sum/2])
            return true;
    }
    return false;
}
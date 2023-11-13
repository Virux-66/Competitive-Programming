#include <bits/stdc++.h>

/**
 * Algorithms: Minimum number of jumps to reach end
 * Type: DP
 * Statement: Given an positive integer N and a list of N integers A[]. 
 * Each element in the array denotes the maximum length of jump you can cover. 
 * Find out if you can make it to the last index if you start at the first index of the list.
 * And if you can reach the end, find the minimum number of jumps.
 * Analysis: This problem is different from stair climbing problem where one floor of a stair
 * can either jump forward one or two step. In this problem, for any floor i, it's possible to
 * reach from 0 to i-1. So we can't adpat the same algorithm to stair climbing problem.
 * Time Complexity: O(N)
*/
int minimumJump(std::vector<int> nums){
    int n = nums.size();
    std::vector<int> dp(n + 1, 0);
    int end = 0;
    for(int i = 0; i < n; i++){
        if(end >= n - 1){
            break;
        }
        if(nums[i] == 0 && i == end){
            return 0; // indicate non-reachable
        }
        if(i + nums[i] > end){
            dp[end + 1] = dp[i] + 1;
            end = i + nums[i];
        }
    }
    return dp[n - 1];
}

int canReach(std::vector<int> nums){
        int n = nums.size();
        int farthest = 0;
        farthest += nums[0];
        for(int i = 1; i < n; ++i){
            if(i <= farthest){
                farthest = std::max(farthest, i + nums[i]);
            }else{
                return 0;
            }
        }
        return 1;
}
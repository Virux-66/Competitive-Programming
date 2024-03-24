#include <bits/stdc++.h>
using namespace std;

/**
 * Algorithm: longest increasing subsequence
 * Type: DP
 * Statement: Given an integer array nums, return the length of the longest strictly increasing subsequence
 * Analysis: For a sequence S, its longest increasing subsequence must end with one of element, S[i]
 * where i from 0 to n-1. Therefore, for any S[i], if we can find the longest increasing subsequence ending with it,
 * we then only pick the maximun among them.
 * Let dp[i] be the number of longest increasing subsequence ending with S[i], the recursive relation is:
 * dp[i] = 1 + max(dp[j]) where j from 0 to i-1 and S[i] > S[j].
 * dp[i] = 1 if no such a j that S[j] < S[i].
 * OJ: https://leetcode.cn/problems/longest-increasing-subsequence/
*/

int longestIncreasingSubsequence(std::vector<int>& num){
    int n = num.size();
    std::vector<int> dp(n, 0);
    dp[0] = 1;
    int result = 1;
    for(int i = 1; i < n; i++){
        dp[i] = 1;
        for(int j = 0; j < i; j++){
            if(num[j] < num[i]){
                dp[i] = std::max(dp[i], 1 + dp[j]);
            }
        }
        result = std::max(result, dp[i]);
    }
    return result;
}
/**
 * Algorithm: longest subsequence with difference one.
 * Type: DP
 * Statement: Given an array A, find the longest subsequence
 * such that difference between adjacent elemen is one.
*/
int longestSubsequenceWithDiffOne(std::vector<int>& num){
    int n = num.size();
    std::vector<int> dp(n, 0);
    dp[0] = 1;
    int result = 1;
    for(int i = 1; i < n; i++){
        dp[i] = 1;
        for(int j = 0; j < i; j++){
            if(std::abs(num[i] - num[j]) == 1){
                dp[i] = std::max(dp[i], dp[j] + 1);
            }
        }
        result = std::max(result, dp[i]);
    }
    return result;
}
#include <bits/stdc++.h>
using namespace std;

/**
 * Algorithm: Subset Sum problem
 * Type: DP
 * Statemetn: Given an array of non-negative integers, and a value sum,
 * determine if there is a subset of the given set with sum equal to given sum.
 * OJ: https://www.geeksforgeeks.org/subset-sum-problem-dp-25/
*/

bool isSubsetSum(vector<int>arr, int sum){
    int N = arr.size();
    std::vector<std::vector<bool>> dp(sum + 1, std::vector<bool>(N, false));
    
    for(int j = 0; j < N; j++){
        dp[0][j] = true;   
    }
    for(int i = 1; i <= sum; i++){
        if(arr[0] == i){
            dp[i][0] = true;
        }
    }
    
    for(int i = 1; i <= sum; i++){
        for(int j = 1; j < N; j++){
            if(arr[j] > i){
                dp[i][j] = dp[i][j - 1];
            }else{
                dp[i][j] = dp[i][j - 1] || dp[i - arr[j]][j - 1];
            }
        }
    }
    return dp[sum][N - 1];
}
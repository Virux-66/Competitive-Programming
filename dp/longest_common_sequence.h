#include<bits/stdc++.h>

/**
 * Algorithm: Longest common sequence
 * Type: DP
 * Statement: Given two strings word1 and word2, return the length of
 * their longest common subsequence. If there is no common subsequence
 * return 0
 * OJ: https://leetcode.cn/problems/longest-common-subsequence/
*/
int longestCommonSubsequence(std::string word1, std::string word2){
    int n = word1.length(), m = word2.length();
    std::vector<std::vector<int>> dp(n+1, std::vector<int>(m+1, 0));
    for(int i=1; i<=n; i++){
	   for(int j=1; j<=m; j++){
		   if(word1[i-1] == word2[j-1]){
			  dp[i][j] = std::max(1+dp[i-1][j-1],std::max(dp[i-1][j],dp[i][j-1]));
		    }else{
			  dp[i][j] = std::max(dp[i-1][j],dp[i][j-1]);
		    }
	    }   
    }
    return dp[n][m];
}

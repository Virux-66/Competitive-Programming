#include<bits/stdc++.h>
using namespace std;

/**
 * Algorithm: Longest common sequence
 * Type: DP
 * Statement: Given two strings word1 and word2, return the length of
 * their longest common subsequence. If there is no common subsequence
 * return 0
*/
int longestCommonSubsequence(string word1, string word2){
    int n = word1.length(), m = word2.length();
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    for(int i=1; i<=n; i++){
	   for(int j=1; j<=m; j++){
		   if(word1[i-1] == word2[j-1]){
			  dp[i][j] = max(1+dp[i-1][j-1],max(dp[i-1][j],dp[i][j-1]));
		    }else{
			  dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
		    }
	    }   
    }
    return dp[n][m];
}

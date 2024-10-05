#include<bits/stdc++.h>

/**
 * Algorithm: Edit distance
 * Type: DP
 * Statement: Given two strings word1 and word2, return the minimum number of operations
 * required to convert word1 and word2
 * You have the following three operations permitted on a word:
 * - Insert a character
 * - Delete a character
 * - Replace a character
 * Detail: Let dp[i][j] be the minimum distance between the first i character of word1 
 * and the first j character of word2.
 * dp[i][j] = min(dp[i-1][j-1],1 + min(dp[i-1][j],dp[i][j-1])) if word1[i-1] = word2[j-1]
 * dp[i][j] = 1 + min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1])) if word1[i-1] != word2[j-1]
 * OJ: https://leetcode.cn/problems/edit-distance/description/
*/

int minDistance(std::string word1, std::string word2) {
   	int n = word1.length(), m =word2.length();
    std::vector<std::vector<int>> dp(n+1, std::vector<int>(m+1));
    for(int j=0; j<=m; j++){
     dp[0][j] = j;
    }
    for(int i=0; i<=n; i++){
     dp[i][0] = i;
    }
    
    for(int i=1; i<=n; i++){
     for(int j=1; j<=m; j++){
      if(word1[i-1] == word2[j-1]){
       dp[i][j] = std::min(dp[i-1][j-1],1 + std::min(dp[i-1][j],dp[i][j-1]));
      }else{
       dp[i][j] = 1 + std::min(dp[i-1][j-1],std::min(dp[i-1][j],dp[i][j-1]));
      }
     }
    }
    return dp[n][m];
}

#include<bits/stdc++.h>

/**
 * Algorithm: longest common substring
 * Type: DP
 * Statement: Given two string. Find the longest substring.
 * OJ: https://www.geeksforgeeks.org/longest-common-substring-dp-29/
*/

int longestCommonSubstring(std::string word1, std::string word2){
    int n = word1.length(), m = word2.length();
    std::vector<std::vector<int>> dp(n+1, std::vector<int>(m+1,0));
    int result = -1;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(word1[i-1] == word2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }else{
                dp[i][j] = 0;
            }
            result = std::max(result, dp[i][j]);
        }
    }
    return result;
}
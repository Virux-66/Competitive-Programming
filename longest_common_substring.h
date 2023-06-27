#include<bits/stdc++.h>
using namespace std;

/**
 * Algorithm: longest common substring
 * Type: DP
 * Statement: Given two string. Find the longest substring.
*/

int longestCommonSubstring(string word1, string word2){
    int n = word1.length(), m = word2.length();
    vector<vector<int>> dp(n+1, vector<int>(m+1,0));
    int result = -1;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(word1[i-1] == word2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }else{
                dp[i][j] = 0;
            }
            result = max(result, dp[i][j]);
        }
    }
    return result;
}
#include <bits/stdc++.h>

/**
 * Algorithm: word break
 * Statement: Given a string s and a dictionary of strings wordDict, 
 * return true if s can be segmented into a space-separated sequence of one 
 * or more dictionary words.
 * Type: DP
*/

bool wordBreak(std::string s, std::vector<std::string>& wordDict) {
    int n = s.size();
    std::vector<std::vector<bool>> dp(n, std::vector<bool>(n, false));
    std::set<std::string> dict;
    for(auto str: wordDict){
        dict.insert(str);
    }
    for(int i = 0; i < n; i++){
        std::string str(s.begin() + i, s.begin() + i + 1);
        if(dict.find(str) != dict.end()){
            dp[i][i] = true;
        }
    }

    for(int i = n - 2; i >= 0; i--){
        for(int j = i + 1; j < n; j++){
            std::string str(s.begin() + i, s.begin() + j +1);
            if(dict.find(str) != dict.end()){
                dp[i][j] = true;
            }else{
                for(int k = i; k < j; k++){
                    if(dp[i][k] && dp[k + 1][j]){
                        dp[i][j] = true;
                        break;
                    }
                }
            }
        }
    }
    return dp[0][n - 1];
}
#include<bits/stdc++.h>
using namespace std;

/**
 * Algorithm: Rod cutting
 * Type: DP
 * Statement: Given a rod of length N inches and array of prices.
 * prices[i] denotes that value of a piece of length i.
 * Determine the maximum value obtainable by cutting up the rod.
*/

int rodCutting(vector<int> prices){
    int n = prices.size();
    vector<int> dp(n + 1, 0);
    dp[0] = 0;
    dp[1] = prices[0];
    for(int i = 2; i <= n; i++){
        for(int j = 1; j < i; j++){
            dp[i] = max(dp[i], max(dp[j] + dp[j - i], prices[i - 1]));
        }
    }
    return dp[n];
}
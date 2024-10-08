#include<bits/stdc++.h>
/**
 * Algorithm: Best time to buy and sell stock
 * Type: DP
 * Statement: You are given an integer array prices where prices[i] 
 * is the price of a given stock on the ith day, and an integer k.
 * Find the maximum profile you can achieve. You may complete
 * at most k transaction: i.e. you may buy at most k times and sell
 * at most k times.
 * Detail: buy[i][j] represents the maximum profile for prices[0...i]
 * with j transactions where the stock is kept.
 * sell[i][j] represents the maximum profile for prices[0...i] with
 * j transactions where the stock is not kept.
 * OJ: https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-iv/
*/
int maxProfit(int k, std::vector<int>& prices) {
    int n = prices.size();
    std::vector<std::vector<int>> buy(n,std::vector<int>(k+1));
    std::vector<std::vector<int>> sell(n,std::vector<int>(k+1));
    buy[0][0] = -prices[0];
    for(int i=1; i<=k; i++){
        buy[0][i] = INT_MIN;
    }
    for(int i=1; i<n; i++){
        buy[i][0] = std::max(-prices[i],buy[i-1][0]);
    }
    for(int i=0; i<=k; i++){
        sell[0][i] = 0;
    }
    for(int i=0; i<n; i++){
        sell[i][0] = 0;
    }
    for(int i=1; i<n; i++){
        for(int j=1; j<=k; j++){
            buy[i][j]=std::max(buy[i-1][j],sell[i-1][j]-prices[i]);
            sell[i][j]=std::max(sell[i-1][j],buy[i-1][j-1]+prices[i]);
        }
    }
    int result = 0; 
    for(int i=0; i<=k; i++){
        result = std::max(result, sell[n-1][i]);
    }
    return result;
}
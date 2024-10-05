#include<bits/stdc++.h>

/**
 * Algorithm: Maxtri Chain Multiplication
 * Type: DP
 * Statement: Given a sequence of matrices, find the most efficient way to multiply
 * these matrices together. The efficient way is the one that involves the least
 * number of multiplication
 * OJ: https://www.geeksforgeeks.org/matrix-chain-multiplication-dp-8/
*/

int matrixMulplication(std::vector<int> arr){
    int n = arr.size();
    std::vector<std::vector<int>> dp(n-1, std::vector<int>(n-1,INT_MAX));
    for(int i=0; i<n-1; i++){
        dp[i][i] = 0;
    }
    for(int j=1; j<n-1; j++){
        for(int i=0; j+i<n-1; i++){
           for(int k=i; k<j+i; k++){
                dp[i][j+i]=std::min(dp[i][j+i],dp[i][k]+dp[k+1][j+i]+arr[i]*arr[k+1]*arr[j+i+1]);
           } 
        }
    }
    return dp[0][n-2];
}
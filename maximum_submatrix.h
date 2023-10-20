#include <bits/stdc++.h>

/**
 * Algorithm: Maximum size square sub-matrix with all 1s
 * Type: DP
 * Statement:Given a binary matrix, find out the maximum size square sub-matrix with all 1s. 
 * For example, consider the below binary matrix. 
 * Detail: Calculate dp[i][j] based upon dp[i-1][j-1]
*/
int maxSquare(int n, int m, std::vector<std::vector<int>> mat){
    // code here
    std::vector<std::vector<int>> vertical(n, std::vector<int>(m, 0));
    std::vector<std::vector<int>> horizontal(n, std::vector<int>(m, 0));
    std::vector<std::vector<int>> dp(n, std::vector<int>(m, 0));
    
    for(int i = 0; i < n; i++){
        horizontal[i][0] = 0;
        for(int j = 1; j < m; j++){
            horizontal[i][j] = horizontal[i][j - 1] + mat[i][j - 1];
        }
    }
    for(int j = 0; j < m; j++){
        vertical[0][j] = 0;
        for(int i = 1; i < n; i++){
            vertical[i][j] = vertical[i - 1][j] +mat[i - 1][j];
        }
    }
    int result = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(mat[i][j] == 1){
                dp[i][j] = 1;
                result = 1;
            }
        }
    }

    for(int i = 1; i < n; i++){
        for(int j = 1; j < m; j++){
            if(mat[i][j] == 1){
                int size = dp[i - 1][j - 1];
                if( size == 0){
                    dp[i][j] = 1;
                }else{
                    int x = (i - 1) - size + 1;
                    int y = (j - 1) - size + 1;
                    if(vertical[i][j] - vertical[x][j] == size &&
                        horizontal[i][j] - horizontal[i][y] == size){
                            dp[i][j] = dp[i - 1][j - 1] + 1;
                    }else{
                        dp[i][j] = 1;
                    }
                }
            }else{
                dp[i][j] = 0;
            }
            result = std::max(result, dp[i][j]);
        }
    }
    return result;
}
#include<bits/stdc++.h>
/**
 * Algorithm: binary exponentiation
 * best/wrose: O(logN)
*/

long long BinaryExponentiation(long long x, long long n) {
    if(n == 0){
        return 1;
    }
    if(n % 2 == 0){
        auto half = BinaryExponentiation(x, n / 2);
        return half * half;
    }else{
        return x * BinaryExponentiation(x, n - 1);
    }
}
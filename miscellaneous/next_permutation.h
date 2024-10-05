#include<bits/stdc++.h>

/**
 * Alogrithm: Find the next permutation
 * Type: 
 * Detail: The key observation in this algorithm is that
 * when we want to compute the next permutation, we must "increase"
 * the sequence as little as possible. 
 *
 * Firstly, identify the longest suffix that is non-increasing.
 * This suffix is already the highest permutation, so we can't 
 * make a next permutation just by modifying it - we need to modify 
 * some elements to the left of it.
 * 
 * Secondly, look at the element immediately to the left of the suffix
 * and call it the pivot. If there is no such element - i.e. the entire
 * sequence is non-increasing - then this already the last permutation.
 * Swap the pivot with the smallest element in the suffix that is greater
 * than the pivot, then the prefix is minimally increased.
 * 
 * Finally, we sort the suffix in non-decreasing order because
 * increase the prefix, so we want to make the new suffix as low as
 * possible.
*/

void nextPermutation(std::vector<int>& nums) {
    int n = nums.size();
    int pivot = -1;
    for(int i = n-1; i>=1; i--){
        if(nums[i-1] < nums[i]){
            pivot = i - 1;
            break;    
        }
    }

    if(pivot == -1){
        reverse(nums.begin(), nums.end());
        return;
    }

    auto itera = upper_bound(nums.rbegin(),nums.rbegin() + n - 1 - pivot - 1, nums[pivot]);
    int tmp = *itera;
    *itera = nums[pivot];
    nums[pivot] = tmp;

    reverse(nums.begin() + pivot + 1, nums.end()); 

    return;
}
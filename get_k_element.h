#include <bits/stdc++.h>

/**
 * Algorithm: get the k th smallest element in one array or two arrays.
 * Type: binary search
 * Statement: find the k th smallest element in one array is very simple.
 * But it's not easy to do in two sorted arrays.
 * OJ: https://leetcode.cn/problems/median-of-two-sorted-arrays/description/
 */

int findKth_one_stub(std::vector<int>& nums, int left, int right, int k){
    int l = left;
    int r = right;
    int pivot = nums[left];

    while(l <= r){
        if(l == r){
            nums[l] = pivot;
            break;
        }
        for(; l < r; r--){
            if(nums[r] < pivot){
                nums[l] = nums[r];
                break;
            }
        }
        for(; l < r; l++){
            if(nums[l] > pivot){
                nums[r] = nums[l];
                break;
            }
        }
    }

    if(l - left + 1 == k){
        return nums[l];
    }else if(l - left + 1 < k){
        return findKth_one_stub(nums, l + 1, right, k - (l - left + 1));
    }else{
        return findKth_one_stub(nums, left, l - 1, k);
    }
}

int findKth_one(std::vector<int>& nums, int k){
    int n = nums.size();
    return  findKth_one_stub(nums, 0, n - 1, k);
}


int findKth_two(std::vector<int>& nums1, std::vector<int>& nums2, int k){
    int n = nums1.size();
    int m = nums2.size();

    int index1 = 0;
    int index2 = 0;

    while(true){
        if(index1 == n){
            return nums2[index2 + k - 1];
        }
        if(index2 == m){
            return nums1[index1 + k - 1];
        }

        if(k == 1){
            return std::min(nums1[index1], nums2[index2]);
        }

        int newIndex1 = std::min(index1 + k / 2 - 1, n - 1);
        int newIndex2 = std::min(index2 + k / 2 - 1, m - 1);
        int pivot1 = nums1[newIndex1];
        int pivot2 = nums2[newIndex2];
        if(pivot1 <= pivot2){
            k -= newIndex1 - index1 + 1;
            index1 = newIndex1 + 1;
        }else{
            k -= newIndex2 - index2 + 1;
            index2 = newIndex2 + 1;
        }
    }
}
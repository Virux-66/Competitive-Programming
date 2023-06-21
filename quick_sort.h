#include<bits/stdc++.h>
using namespace std;

/**
 * Algorithm: quick sort
 * best: O(NlogN)
 * Avg:  O(NlogN)
 * worse: O(N^2)
*/

void quickSort(vector<int>&nums, int l,int r){
  if(l>=r)
      return;
  int pivot=nums[l];
  int left=l,right=r;
  while(left<right){
      for(;left!=right;right--){
      if(nums[right]<pivot){
          nums[left]=nums[right];
              break;
          }
      }
      for(;left!=right;left++){
          if(nums[left]>pivot){
              nums[right]=nums[left];
              break;
          }
      }
  }
  nums[left]=pivot;
  quickSort(nums,l,left-1);
  quickSort(nums,left+1,r);
}

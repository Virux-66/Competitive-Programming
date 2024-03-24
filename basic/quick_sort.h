#include<bits/stdc++.h>

/**
 * Algorithm: quick sort
 * best: O(NlogN)
 * Avg:  O(NlogN)
 * worse: O(N^2)
*/

template<typename T, typename Comp = std::less<T>>
void QuickSort(std::vector<T>& nums, int l,int r){
  Comp comp;
  if(l >= r)
      return;
  int pivot = nums[l];
  int left = l,right = r;
  while(left < right){
      for(; left != right; right--){
        if(comp(nums[right], pivot)){
            nums[left] = nums[right];
                break;
            }
      }
      for(;left != right; left++){
          if(comp(pivot, nums[left])){
              nums[right] = nums[left];
              break;
          }
      }
  }
  nums[left] = pivot;
  QuickSort(nums, l, left-1);
  QuickSort(nums, left+1, r);
}

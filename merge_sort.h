#include<bits/stdc++.h>
/**
 * Algorithm: merge sort
 * best: O(NlogN)
 * Avg: O(NlogN)
 * wrose: O(NlogN)
*/
using namespace std;
void mergeSort(vector<int>& nums,int l,int r){
    if(l==r)
        return;
    int mid=(l+r)/2;
    mergeSort(nums,l,mid);
    mergeSort(nums,mid+1,r);
    int i=l,j=mid+1;
    vector<int> tmp;
    while(i<=mid || j<=r){
        if(i<=mid && j<=r){
           if(nums[i]<nums[j]){
               tmp.push_back(nums[i]);
               i++;
           }else{
               tmp.push_back(nums[j]);
               j++;
           }
       }else{
           if(i<=mid){
               for(;i<=mid;i++)
                   tmp.push_back(nums[i]);
           }else{
               for(;j<=r;j++)
                   tmp.push_back(nums[j]);
           }
           break;
       }
    }
    for(int index=l,tmp_index=0;index<=r;index++,tmp_index++)
        nums[index]=tmp[tmp_index];
    return;
}
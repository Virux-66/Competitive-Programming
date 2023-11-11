#include<bits/stdc++.h>

/**
 * Algorithm: Monotonic Stack
 * Detail: An monotonic stack is a stack whose elements are
 * monotonically increasing or descreasing. Sometimes we store
 * the index of the elements in the stack and make sure
 * the elements corresponding to those indexes in the stack
 * forms a mono-sequence.
 * OJ: https://leetcode.cn/problems/daily-temperatures/description/
 */
std::vector<int> dailyTemperatures(std::vector<int>& temperatures){
    int n = temperatures.size();
    std::stack<int> s;
    std::vector<int> ans(n, 0);
    for(int i = 0; i < temperatures.size(); ++i){
        if(s.empty()){
            s.push(i);
            continue;
        }
        if(temperatures[s.top()] < temperatures[i]){
            while(!s.empty() && temperatures[s.top()] < temperatures[i]){
                int index = s.top();
                s.pop();
                ans[index] = i - index;
            }
            s.push(i);
        }else{
            s.push(i);
        }
    }
    return ans;
}
#include<bits/stdc++.h>

/**
 * Algorithm: Monotonic Stack
 * Detail: An monotonic stack is a stack whose elements are
 * monotonically increasing or descreasing. Sometimes we store
 * the index of the elements in the stack and make sure
 * the elements corresponding to those indexes in the stack
 * forms a mono-sequence.
 */

template <typename T, typename Compare = std::greater<T>>
class MonotonicStack{
    public:
        MonotonicStack(std::vector<T>& v) : vec_(v){}
        void Push(int index){
            T value = vec_[index];
            if(sk_.empty()){
                sk_.push(index);
                return;
            }
            while(sk_.size() && !comp_(value, vec_[sk_.top()])){
                sk_.pop();
            }
            sk_.push(index); 
        }

        T Pop(){
            auto value = sk_.top();
            sk_.pop();
            return value;
        }
        

        std::vector<T> vec_;
        std::stack<T> sk_;
        Compare comp_;
};
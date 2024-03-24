#include<bits/stdc++.h>
/**
 * Data structure: segment tree
 * Construction: O(N)
 * Query: O(logN)
 * Modification: O(logN)
 */
template <typename T>
class TreeNode{
    public:
        T val;
        TreeNode<T>* left;
        TreeNode<T>* right;
        int left_index;
        int right_index;
        TreeNode():left(nullptr), right(nullptr){}
        TreeNode(T v): val(v), left(nullptr), right(nullptr){}
};

template<typename T, typename Func>
class SegmentTree{
    public:
        TreeNode<T>* root_;
        Func functor_;
        SegmentTree(std::vector<T> vec){
            int n = vec.size();
            root_ = Build(vec, 0, n - 1);
        }

        TreeNode<T>* Build(std::vector<T>& vec, int left_index, int right_index){
            if(left_index == right_index){
                TreeNode<T>* root = new TreeNode<T>(vec[left_index]);
                root->left_index = root->right_index = left_index;
                return root;
            }else{
                TreeNode<T>* root = new TreeNode<T>();
                root->left = Build(vec, left_index, (left_index + right_index) / 2);
                root->right = Build(vec, (left_index + right_index) / 2 + 1, right_index);
                root->val = functor_(root->left->val, root->right->val);
                root->left_index = left_index;
                root->right_index = right_index;
                return root;
            }
        }

        T Query(int left_index, int right_index){
            return QueryStub(root_, left_index, right_index);
        }

        T QueryStub(TreeNode<T>* root, int left_index, int right_index){
            if(left_index > right_index){
                return 0;
            }
            if(root->left_index == left_index && root->right_index == right_index){
                return root->val;
            }
            
            int mid = (root->left_index + root->right_index) / 2;
        
            if(right_index <= mid){
                return QueryStub(root->left, left_index, right_index);
            }else if(left_index >= mid + 1){
                return QueryStub(root->right, left_index, right_index);
            }else{
                return functor_(QueryStub(root->left, left_index, mid),
                        QueryStub(root->right, mid + 1, right_index));
            }
        }

        void Update(int pos, T new_val){
            UpdateStub(root_, pos, new_val);
        }
        
        void UpdateStub(TreeNode<T>* root, int pos, T new_val){
            if(root->left_index == root->right_index){
                root->val = new_val;
                return;
            }

            int mid = (root->left_index + root->right_index) / 2;
            if(pos <= mid){
                UpdateStub(root->left, pos, new_val);
            }else{
                UpdateStub(root->right, pos, new_val);
            }
            root->val = root->left->val + root->right->val;
        }
};
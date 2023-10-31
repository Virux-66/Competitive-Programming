#include<bits/stdc++.h>
/**
 * Data structure: segment tree
 * Construction: O(N)
 * Query: O(logN)
 * Modification: O(logN)
 */

class TreeNode{
    public:
        int val;
        TreeNode* left;
        TreeNode* right;
        int left_index;
        int right_index;
        TreeNode():val(0), left(nullptr), right(nullptr){}
        TreeNode(int v): val(v), left(nullptr), right(nullptr){}
};

class segment_tree{
    public:
        TreeNode* root;
        segment_tree(std::vector<int> vec){
            int n = vec.size();
            root = build(vec, 0, n - 1);
        }

        TreeNode* build(std::vector<int>& vec, int left_index, int right_index){
            if(left_index == right_index){
                TreeNode* root = new TreeNode(vec[left_index]);
                root->left_index = root->right_index = left_index;
                return root;
            }else{
                TreeNode* root = new TreeNode();
                root->left = build(vec, left_index, (left_index + right_index) / 2);
                root->right = build(vec, (left_index + right_index) / 2 + 1, right_index);
                root->val = root->left->val + root->right->val;
                root->left_index = left_index;
                root->right_index = right_index;
                return root;
            }
        }

        int query(int left_index, int right_index){
            return queryStub(root, left_index, right_index);
        }

        int queryStub(TreeNode* root, int left_index, int right_index){
            if(left_index > right_index){
                return 0;
            }
            if(root->left_index == left_index && root->right_index == right_index){
                return root->val;
            }
            
            int mid = (root->left_index + root->right_index) / 2;
        
            if(right_index <= mid){
                return queryStub(root->left, left_index, right_index);
            }else if(left_index >= mid + 1){
                return queryStub(root->right, left_index, right_index);
            }else{
                return queryStub(root->left, left_index, mid) + 
                        queryStub(root->right, mid + 1, right_index);
            }
        }

        void update(int pos, int new_val){
            updateStub(root, pos, new_val);
        }
        
        void updateStub(TreeNode* root, int pos, int new_val){
            if(root->left_index == root->right_index){
                root->val = new_val;
                return;
            }

            int mid = (root->left_index + root->right_index) / 2;
            if(pos <= mid){
                updateStub(root->left, pos, new_val);
            }else{
                updateStub(root->right, pos, new_val);
            }
            root->val = root->left->val + root->right->val;
        }
};
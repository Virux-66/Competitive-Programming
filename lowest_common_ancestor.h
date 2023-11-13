#include <bits/stdc++.h>

/**
 * Algorithm: lowest common ancestor of a binary tree
 * Type: Recusive
 * Statement: Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.
 * OJ: https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-tree/description/
 */


class TreeNode{
    public:
        int val;
        TreeNode* left;
        TreeNode* right;
        TreeNode(int x): val(x), left(nullptr), right(nullptr){}
};

std::map<int, int> index;

    void dfs_inorder(TreeNode* root, std::vector<int>& inorder){
        if(root == nullptr){
            return;
        }
        dfs_inorder(root->left, inorder);
        inorder.push_back(root->val);
        dfs_inorder(root->right, inorder);
    }
    void dfs_preorder(TreeNode* root, std::vector<int>& preorder){
        if(root == nullptr){
            return;
        }
        preorder.push_back(root->val);
        dfs_preorder(root->left, preorder);
        dfs_preorder(root->right, preorder);
    }

    int commonParent(std::vector<int>& preorder, int preorder_left, int preorder_right, std::vector<int>& inorder, int inorder_left, int inorder_right, TreeNode* p, TreeNode* q){
        //std::cout << "preorder_left: " << preorder_left << std::endl;
        //std::cout << "preorder_right: " << preorder_right<< std::endl;
        //std::cout << "inorder_left: " << inorder_left << std::endl;
        //std::cout << "inorder_right: " << inorder_right<< std::endl;
        if(preorder_left > preorder_right){
            return -1;
        }
        int preorder_root = preorder_left;
        int inorder_root = index[preorder[preorder_root]]; 
        if(inorder[inorder_root] == p->val || inorder[inorder_root] == q->val){
            return inorder[inorder_root];
        }else{
            if((index[inorder[inorder_root]] - index[p->val]) * (index[inorder[inorder_root]] - index[q->val]) < 0){
                return inorder[inorder_root];
            }else{
                int left_subtree_size = inorder_root - inorder_left;
                int right_subtree_size = inorder_right - inorder_root;
                if(index[inorder[inorder_root]] - index[p->val] > 0){
                    return commonParent(preorder, preorder_left + 1, preorder_left + left_subtree_size, inorder, inorder_left, inorder_root - 1, p, q);
                }else{
                    return commonParent(preorder, preorder_left + left_subtree_size + 1, preorder_right, inorder, inorder_root + 1, inorder_right, p, q);
                }
            }
        }
    }
 
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        std::vector<int> inorder;
        std::vector<int> preorder;
        dfs_inorder(root, inorder);
        dfs_preorder(root, preorder);
        int n = inorder.size();
        for(int i = 0; i < n; i++){
            index[inorder[i]] = i;
        }
        for(auto& val: preorder){
            std::cout << val;
        }
        std::cout << std::endl;
        for(auto& val: inorder){
            std::cout << val;
        }
        std::cout << std::endl;
        int value = commonParent(preorder, 0, n - 1, inorder, 0, n - 1, p, q);
        return new TreeNode(value);
    }

    TreeNode* lowestCommonAncestorRecursive(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root == nullptr || root == p || root == q){
            return root;
        }
        TreeNode* left = lowestCommonAncestorRecursive(root->left, p, q);
        TreeNode* right= lowestCommonAncestorRecursive(root->right, p, q);
        if(left == nullptr && right == nullptr){
            return nullptr;
        }
        if(left == nullptr){
            return right;
        }
        if(right == nullptr){
            return left;
        }
        return root;
    }
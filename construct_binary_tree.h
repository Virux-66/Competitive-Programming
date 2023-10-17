#include<bits/stdc++.h>

/**
 * Algorithm: construct binary tree via its preorder and inorder
 * Type: Tree, recursive
 */

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(): val(0), left(nullptr), right(nullptr){}
    TreeNode(int x): val(x), left(nullptr), right(nullptr){}
    TreeNode(int x, TreeNode* left, TreeNode* right): val(x), left(left), right(right){}
};

std::map<int,int> index;
TreeNode* buildTreeStub(std::vector<int>& preorder, std::vector<int>& inorder, int preorder_left, int preorder_right, int inorder_left, int inorder_right){
    if(preorder_left > preorder_right){
        return nullptr;
    }
    int preorder_root = preorder_left;
    int inorder_root = index[preorder[preorder_root]];    

    TreeNode* root = new TreeNode(preorder[preorder_root]);

    int size_left_subtree = inorder_root - inorder_left;
    int size_right_subtree = inorder_right - inorder_root;

    root->left = buildTreeStub(preorder, inorder, preorder_left + 1, preorder_left + size_left_subtree, inorder_left, inorder_root - 1);
    root->right = buildTreeStub(preorder, inorder, preorder_left + size_left_subtree + 1, preorder_right, inorder_root + 1, inorder_right);

    return root;
}
TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder) {
    int n = preorder.size();
    for(int i = 0; i < inorder.size(); i++){
        index[inorder[i]] = i;
    }

    TreeNode*  root = buildTreeStub(preorder, inorder, 0, n - 1, 0, n - 1);
    return root;
}

/**
 * Algorithm: construct binary tree via its inorder and postorder
 * Type: Tree, recursive
 */

TreeNode* buildTreeStub(std::vector<int>& inorder, std::vector<int>& postorder, int inorder_left, int inorder_right, int postorder_left, int postorder_right){
    if(postorder_left > postorder_right){
        return nullptr;
    }

    int postorder_root = postorder_right;
    int inorder_root = index[postorder[postorder_root]];

    int left_size_subtree = inorder_root - inorder_left;
    int right_size_subtree = inorder_right - inorder_root;

    TreeNode* root = new TreeNode(postorder[postorder_root]);

    root->left = buildTreeStub(inorder, postorder, inorder_left, inorder_root - 1, postorder_left, postorder_root - right_size_subtree - 1);

    root->right = buildTreeStub(inorder, postorder, inorder_root + 1, inorder_right, postorder_root - right_size_subtree, postorder_root - 1);


    return root;
}

TreeNode* buildTree(std::vector<int>& inorder, std::vector<int>& postorder) {
    int n = inorder.size();

    for(int i = 0; i < n; i++){
        index[inorder[i]] = i;
    }

    TreeNode* root = buildTreeStub(inorder, postorder, 0, n - 1, 0, n - 1);
    return root;
}
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void flatten(TreeNode* root) {
        if (root == nullptr) return;

        flatten(root->left);
        flatten(root->right);

        TreeNode *left = root->left;
        TreeNode *right = root->right;

        root->left = nullptr;
        root->right = left;
        
        TreeNode *target = root;
        while(target->right != nullptr)
            target = target->right;

        target->right = right;
    }
};

// recursive
// 1. flatten left & right
// 2. since we need pre-order travers, connect root's right to the left, and then connect the original right to the end of left
// Runtime: 8 ms, faster than 46.68% of C++ online submissions for Flatten Binary Tree to Linked List.
// Memory Usage: 12.7 MB, less than 35.71% of C++ online submissions for Flatten Binary Tree to Linked List.

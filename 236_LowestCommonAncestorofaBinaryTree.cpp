/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) return nullptr;
        if (p == root || q == root) return root;
        
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);
        
        if (left != nullptr && right != nullptr) return root;
        if (left == nullptr && right == nullptr) return nullptr;
        
        return left == nullptr ? right : left;
    }
};

// Runtime: 20 ms, faster than 24.75% of C++ online submissions for Lowest Common Ancestor of a Binary Tree.
// Memory Usage: 14 MB, less than 92.64% of C++ online submissions for Lowest Common Ancestor of a Binary Tree.
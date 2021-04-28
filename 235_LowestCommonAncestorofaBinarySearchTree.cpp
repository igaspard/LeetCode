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
        
        if (p->val > root->val && q->val > root->val) return lowestCommonAncestor(root->right, p, q);
        if (p->val < root->val && q->val < root->val) return lowestCommonAncestor(root->left, p, q);
        return root;
    }
};

// Runtime: 24 ms, faster than 93.00% of C++ online submissions for Lowest Common Ancestor of a Binary Search Tree.
// Memory Usage: 23.2 MB, less than 36.76% of C++ online submissions for Lowest Common Ancestor of a Binary Search Tree.

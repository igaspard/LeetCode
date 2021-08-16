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
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) return nullptr;
        
        invertTree(root->left);
        invertTree(root->right);
        
        TreeNode* tmp = root->left;
        root->left = root->right;
        root->right = tmp;
        
        return root;
    }
};

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) return nullptr;

        TreeNode *tmp = root->left;
        root->left = root->right;
        root->right = tmp;

        invertTree(root->left);
        invertTree(root->right);

        return root;
    }
};

// Preorder, postorder
// tree, recursive 
// Runtime: 4 ms, faster than 52.68% of C++ online submissions for Invert Binary Tree.
// Memory Usage: 9.8 MB, less than 5.64% of C++ online submissions for Invert Binary Tree.
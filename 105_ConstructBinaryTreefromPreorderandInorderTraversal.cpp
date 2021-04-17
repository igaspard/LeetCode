/*
 * @lc app=leetcode id=105 lang=cpp
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
 */

// @lc code=start
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return _buildtree(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
    }

    TreeNode* _buildtree(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd) {
        if (preStart > preEnd) return nullptr;

        int root_val = preorder[preStart];
        int idx = 0;
        for (int i = inStart; i <= inEnd; ++i) {
            if (inorder[i] == root_val) {
                idx = i;
                break;
            }
        }
        int left_size = idx - inStart;
        
        TreeNode *root = new TreeNode(root_val);
        root->left = _buildtree(preorder, preStart+1, preStart+left_size, inorder, inStart, idx-1);
        root->right = _buildtree(preorder, preStart+left_size+1, preEnd, inorder, idx+1, inEnd);

        return root;
    }
};
// @lc code=end


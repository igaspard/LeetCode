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
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == nullptr) return false;
        
        if (root->val == sum && root->left == nullptr && root->right == nullptr)
            return true;
        
        return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
    }
};

// DFS
// Time complexity: O(N)
// Space complexity: O(N)
// Runtime: 12 ms, faster than 90.97% of C++ online submissions for Path Sum.
// Memory Usage: 21.2 MB, less than 85.59% of C++ online submissions for Path Sum.
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
    int ans = INT_MIN;
    int maxPathSum(TreeNode* root) {
        oneSideMax(root);
        return ans;
    }

   private:
    int oneSideMax(TreeNode* root) {
        if (root == nullptr) return 0;

        int left = max(0, oneSideMax(root->left));
        int right = max(0, oneSideMax(root->right));

        ans = max(ans, left + right + root->val);
        return max(left, right) + root->val;
    }
};

// DFS, postorder
// Runtime: 24 ms, faster than 99.94% of C++ online submissions for Binary Tree Maximum Path Sum.
// Memory Usage: 28.9 MB, less than 12.06% of C++ online submissions for Binary Tree Maximum Path Sum.
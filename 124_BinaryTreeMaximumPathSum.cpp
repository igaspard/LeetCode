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
    int maxPathSum(TreeNode *root) {
        int ans = numeric_limits<int>::min();
        dfs(root, ans);

        return ans;
    }

    int dfs(TreeNode *root, int &ans) {
        if (root == nullptr) return 0;

        int l = max(0, dfs(root->left, ans));
        int r = max(0, dfs(root->right, ans));
        int sum = l + r + root->val;
        ans = max(ans, sum);

        return max(l, r) + root->val;
    }
};

// DFS
// Runtime: 24 ms, faster than 99.94% of C++ online submissions for Binary Tree Maximum Path Sum.
// Memory Usage: 28.9 MB, less than 12.06% of C++ online submissions for Binary Tree Maximum Path Sum.
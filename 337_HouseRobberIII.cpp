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
    unordered_map<TreeNode*, int> memo;
    int rob(TreeNode* root) {
        if (root == nullptr) return 0;
        if (memo.count(root) != 0) return memo[root];

        int rob_it = root->val +
                     root->left == nullptr ? 0 : rob(root->left->right) + rob(root->left->left) +
                     root->right == nullptr ? 0 : rob(root->right->right) + rob(root->right->left);

        int dont_rob_it = rob(root->left) + rob(root->right);

        memo[root] = max(rob_it, dont_rob_it);
        return memo[root];
    }
};

// recursive w/ memo top down
// Runtime: 16 ms, faster than 66.09% of C++ online submissions for House Robber III.
// Memory Usage: 24.8 MB, less than 56.43% of C++ online submissions for House Robber III.
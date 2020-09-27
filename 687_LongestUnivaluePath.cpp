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
    int longestUnivaluePath(TreeNode* root) {
        int ans = 0;
        
        dfs(root, ans);
        return ans;
    }
    
    int dfs(TreeNode* root, int &ans) {
        if (root == nullptr) return 0;
        
        int left = dfs(root->left, ans);
        int right = dfs(root->right,ans);
        int max_left = 0, max_right = 0;
        if (root->left != nullptr && root->val == root->left->val) {
            max_left = left + 1;
        }
        if (root->right != nullptr && root->val == root->right->val) {
            max_right = right + 1;
        }
        
        ans = max(ans, max_left + max_right);
        return max(max_left, max_right);
    }
};

// DFS
// Runtime: 172 ms, faster than 98.44% of C++ online submissions for Longest Univalue Path.
// Memory Usage: 72.6 MB, less than 5.04% of C++ online submissions for Longest Univalue Path.
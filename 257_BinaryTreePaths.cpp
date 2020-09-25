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
    vector<string> binaryTreePaths(TreeNode *root) {
        vector<string> ans;
        if (root == nullptr) return ans;
        string path;
        dfs(root, path, ans);

        return ans;
    }

    void dfs(TreeNode *root, string path, vector<string> &ans) {
        if (root->left == nullptr && root->right == nullptr) {
            ans.emplace_back(path + to_string(root->val));
        } else {
            if (root->left != nullptr) dfs(root->left, path + to_string(root->val) + "->", ans);
            if (root->right != nullptr) dfs(root->right, path + to_string(root->val) + "->", ans);
        }
    }
};

// DFS
// Runtime: 4 ms, faster than 85.97% of C++ online submissions for Binary Tree Paths.
// Memory Usage: 12.6 MB, less than 93.44% of C++ online submissions for Binary Tree Paths.
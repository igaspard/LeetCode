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
    vector<vector<int>> ans;
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr) return ans;
        dfs(root, 0);
        return ans;
    }

   private:
    void dfs(TreeNode* node, int level) {
        if (ans.size() == level) ans.push_back({});
        ans[level].emplace_back(node->val);

        if (node->left != nullptr) dfs(node->left, level + 1);
        if (node->right != nullptr) dfs(node->right, level + 1);
    }
};

// DFS
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Binary Tree Level Order Traversal.
// Memory Usage: 13.7 MB, less than 6.90% of C++ online submissions for Binary Tree Level Order Traversal.

class Solution {
   public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr) return {};
        queue<TreeNode*> q;
        q.push(root);

        vector<vector<int>> ans;
        vector<int> level;
        while (!q.empty()) {
            auto N = q.size();
            level.clear();
            for (int i = 0; i < N; ++i) {
                auto cur = q.front();
                q.pop();
                level.emplace_back(cur->val);
                if (cur->left != nullptr) q.push(cur->left);
                if (cur->right != nullptr) q.push(cur->right);
            }
            ans.emplace_back(level);
        }

        return ans;
    }
};

// BFS
// Runtime: 8 ms, faster than 36.33% of C++ online submissions for Binary Tree Level Order Traversal.
// Memory Usage: 12.5 MB, less than 83.12% of C++ online submissions for Binary Tree Level Order Traversal.

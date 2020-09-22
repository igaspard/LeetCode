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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == nullptr) return ans;

        queue<TreeNode*> q;
        q.push(root);
        deque<vector<int>> stack;

        while (!q.empty()) {
            int level_size = q.size();
            vector<int> level;
            for (int i = 0; i < level_size; ++i) {
                TreeNode* tmp = q.front();
                q.pop();
                level.emplace_back(tmp->val);

                if (tmp->left != nullptr) q.push(tmp->left);
                if (tmp->right != nullptr) q.push(tmp->right);
            }
            stack.push_front(level);
        }

        while (!stack.empty()) {
            auto it = stack.front();
            stack.pop_front();
            ans.emplace_back(it);
        }

        return ans;
    }
};

// Runtime: 8 ms, faster than 55.41% of C++ online submissions for Binary Tree Level Order Traversal II.
// Memory Usage: 12.9 MB, less than 37.24% of C++ online submissions for Binary Tree Level Order Traversal II.
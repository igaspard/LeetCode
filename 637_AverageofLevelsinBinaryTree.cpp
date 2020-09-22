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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int level_size = q.size();
            long sum = 0;
            for (int i = 0; i < level_size; ++i) {
                TreeNode* tmp = q.front();
                q.pop();
                sum += tmp->val;

                if (tmp->left != nullptr) q.push(tmp->left);
                if (tmp->right != nullptr) q.push(tmp->right);
            }
            ans.emplace_back((double)sum / level_size);
        }

        return ans;
    }
};

Runtime: 32 ms, faster than 25.70% of C++ online submissions for Average of Levels in Binary Tree.
Memory Usage: 22.5 MB, less than 74.70% of C++ online submissions for Average of Levels in Binary Tree.
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
    int minDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        int minimumTreeDepth = 0;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int level_size = q.size();
            minimumTreeDepth++;
            for (int i = 0; i < level_size; ++i) {
                TreeNode* tmp = q.front();
                q.pop();
                if (tmp->left == nullptr && tmp->right == nullptr) return minimumTreeDepth;
                if (tmp->left != nullptr) q.push(tmp->left);
                if (tmp->right != nullptr) q.push(tmp->right);
            }
        }
        return minimumTreeDepth;
    }
};

// BFS
// Runtime: 16 ms, faster than 68.47% of C++ online submissions for Minimum Depth of Binary Tree.
// Memory Usage: 19.9 MB, less than 83.71% of C++ online submissions for Minimum Depth of Binary Tree.
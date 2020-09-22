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
    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        int ans = 0;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int level_size = q.size();
            ans++;
            for (int i = 0; i < level_size; ++i) {
                TreeNode* tmp = q.front();
                q.pop();

                if (tmp->left != nullptr) q.push(tmp->left);
                if (tmp->right != nullptr) q.push(tmp->right);
            }
        }
        return ans;
    }
};

// BSF
// Runtime: 12 ms, faster than 74.82% of C++ online submissions for Maximum Depth of Binary Tree.
// Memory Usage: 19.1 MB, less than 84.55% of C++ online submissions for Maximum Depth of Binary Tree.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
   public:
    int maxDepth(TreeNode* root) {
        if (root)
            return max(maxDepth(root->left), maxDepth(root->right)) + 1;
        else
            return 0;
    }
};

// Recursive
// Runtime: 20 ms, faster than 17.29% of C++ online submissions for Maximum Depth of Binary Tree.
// Memory Usage: 19.4 MB, less than 17.52% of C++ online submissions for Maximum Depth of Binary Tree.
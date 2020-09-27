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
    int sumNumbers(TreeNode* root) {
        int ans = 0;

        dfs(root, 0, ans);
        return ans;
    }

    void dfs(TreeNode* root, int path, int& ans) {
        if (root == nullptr) return;

        int cur = path * 10 + root->val;

        if (root->left == nullptr && root->right == nullptr) {
            ans += cur;
        } else {
            dfs(root->left, cur, ans);
            dfs(root->right, cur, ans);
        }
    }
};

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
    int sumNumbers(TreeNode* root) { return SumTree(root, 0); }

    int SumTree(TreeNode* root, int pathSum) {
        if (root == nullptr) return 0;

        pathSum = pathSum * 10 + root->val;
        if (root->left == nullptr && root->right == nullptr)
            return pathSum;
        else
            return SumTree(root->left, pathSum) + SumTree(root->right, pathSum);
    }
};

// DFS
// Runtime: 4 ms, faster than 83.50% of C++ online submissions for Sum Root to Leaf Numbers.
// Memory Usage: 12.7 MB, less than 26.33% of C++ online submissions for Sum Root to Leaf Numbers.
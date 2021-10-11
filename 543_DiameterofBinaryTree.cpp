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
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        dfs(root, ans);

        return ans;
    }
    int dfs(TreeNode* root, int& ans) {
        if (root == nullptr) return 0;

        int left_height = dfs(root->left, ans);
        int right_height = dfs(root->right, ans);
        ans = max(ans, left_height + right_height);

        return max(left_height, right_height) + 1;
    }
};

// DFS
// tree travers the max tree height, 
// During the travers, diameter is equal to the left tree height + right tree height
// record the max one as the answer
// Runtime: 12 ms, faster than 88.98% of C++ online submissions for Diameter of Binary Tree.
// Memory Usage: 21 MB, less than 16.74% of C++ online submissions for Diameter of Binary Tree.
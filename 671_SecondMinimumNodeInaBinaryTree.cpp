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
    int findSecondMinimumValue(TreeNode *root) {
        unordered_set<int> set;

        traversal(root, set);

        int min1 = root->val;
        long ans = LONG_MAX;
        for (auto it : set) {
            if (it > min1 && it < ans) ans = it;
        }

        return ans < LONG_MAX ? (int)ans : -1;
    }

    void traversal(TreeNode *root, unordered_set<int> &set) {
        if (root == nullptr) return;

        set.insert(root->val);
        traversal(root->left, set);
        traversal(root->right, set);
    }
};

// Runtime: 4 ms, faster than 100.00% of C++ online submissions for Second Minimum Node In a Binary Tree.
// Memory Usage: 7.2 MB, less than 7.67% of C++ online submissions for Second Minimum Node In a Binary Tree.
/*
 * @lc app=leetcode id=654 lang=cpp
 *
 * [654] Maximum Binary Tree
 */

// @lc code=start
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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return BuildMaxBinaryTree(nums, 0, (int)nums.size()-1);
    }

    TreeNode *BuildMaxBinaryTree(vector<int> &nums, int left, int right) {
        if (left > right) return nullptr;
        
        int max_value = std::numeric_limits<int>::min();
        int idx = -1;
        for (int i = left; i <= right; ++i) {
            if (nums[i] > max_value) {
                max_value = nums[i];
                idx = i;
            }
        }

        TreeNode *root = new TreeNode(max_value);
        root->left = BuildMaxBinaryTree(nums, left, idx-1);
        root->right = BuildMaxBinaryTree(nums, idx+1, right);
        
        return root;
    }
};
// @lc code=end

// Your runtime beats 81.34 % of cpp submissions
// Your memory usage beats 71.61 % of cpp submissions (42.2 MB)
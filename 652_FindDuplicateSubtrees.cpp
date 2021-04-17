/*
 * @lc app=leetcode id=652 lang=cpp
 *
 * [652] Find Duplicate Subtrees
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
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string, int> hash;
        vector<TreeNode*> ans;
        traverse(root, hash, ans);
        return ans;
    }

    string traverse(TreeNode* root, unordered_map<string, int> &hash, vector<TreeNode*> &ans) {
        if (root == nullptr) {
            return "#";
        }

        string left = traverse(root->left, hash, ans);
        string right = traverse(root->right, hash, ans);
        string subtree = left + "," + right + "," + to_string(root->val);
        // only add into ans when already find one in hash
        if (hash[subtree] == 1) ans.emplace_back(root);
        hash[subtree]++;

        return subtree;
    }
};
// @lc code=end


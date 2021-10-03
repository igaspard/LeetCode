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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (root == nullptr) return false;

        return isSameTree(root, subRoot) || isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }

   private:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q)
            return true;
        else if ((!p && q) || (p && !q))
            return false;
        else if (p->val != q->val)
            return false;
        else
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

// recursive, use the leetcode #100 same tree.
// Runtime: 20 ms, faster than 81.57% of C++ online submissions for Subtree of Another Tree.
// Memory Usage: 28.9 MB, less than 56.75% of C++ online submissions for Subtree of Another Tree.
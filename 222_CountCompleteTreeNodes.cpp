class Solution {
public:
    int countNodes(TreeNode* root) {
        int left_h = 0, right_h = 0;
        
        auto cur = root;
        while (cur != nullptr) {
            cur = cur->left;
            ++left_h;
        }
        
        cur = root;
        while (cur != nullptr) {
            cur = cur->right;
            ++right_h;
        }
        
        if (left_h == right_h) return (int) pow(2, left_h) - 1;
        else return 1 + countNodes(root->left) + countNodes(root->right);
    }
};

// Number of Perfect Binary Tree is 2^H - 1
// Number of normal binary tree is 1 + countNodes(root->left) + countNodes(root->right)
// check the left and right tree height equal or not, combine above two methods
// Time complexity: O(logN*logN)
// Runtime: 28 ms, faster than 85.75% of C++ online submissions for Count Complete Tree Nodes.
// Memory Usage: 31 MB, less than 21.46% of C++ online submissions for Count Complete Tree Nodes.
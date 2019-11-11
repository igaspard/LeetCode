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
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> s;
        int cnt = 0;
        TreeNode* cur = root;
        while(1) {
            while(cur != NULL) {
                s.push(cur);
                cur = cur->left;
            }
            if(!s.empty()) {
                cur = s.top();
                s.pop();
                cnt++;
                if (cnt == k)
                    return cur->val;
                cur = cur->right;
            }
            else
                break;
        }
        return cur->val;
    }
};

// Runtime: 24 ms, faster than 52.55% of C++ online submissions for Kth Smallest Element in a BST.
// Memory Usage: 21.4 MB, less than 98.33% of C++ online submissions for Kth Smallest Element in a BST.
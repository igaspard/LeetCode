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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder;
        stack<TreeNode*> s;
        TreeNode *cur = root;
        while(1) {
            while(cur != NULL) {
                s.push(cur);
                cur = cur->left;
            }
            if(!s.empty()) {
                cur = s.top();
                s.pop();
                inorder.push_back(cur->val);
                cur = cur->right;
            }
            else
                break;
        }
        return inorder;
    }
};

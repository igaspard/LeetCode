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
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        vector<int> ans;
        
        s.push(root);        
        while(!s.empty()) {
            TreeNode *cur = s.top();
            s.pop();
            
            if (cur!=NULL) {
                ans.emplace_back(cur->val);
                s.push(cur->right);
                s.push(cur->left);
            }
        }
        return ans;
    }
};

// Runtime: 4 ms, faster than 59.18% of C++ online submissions for Binary Tree Preorder Traversal.
// Memory Usage: 9.1 MB, less than 100.00% of C++ online submissions for Binary Tree Preorder Traversal.
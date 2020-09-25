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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if (root == nullptr) return ans;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                TreeNode *tmp = q.front();
                q.pop();
                
                if (i == size - 1) ans.emplace_back(tmp->val);
                if (tmp->left != nullptr) q.push(tmp->left);
                if (tmp->right != nullptr) q.push(tmp->right);
            }
        }
        
        return ans;
     }
};

// BFS
// Runtime: 4 ms, faster than 79.01% of C++ online submissions for Binary Tree Right Side View.
// Memory Usage: 11.7 MB, less than 89.80% of C++ online submissions for Binary Tree Right Side View.
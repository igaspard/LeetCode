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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> out;
        if (root == NULL)
            return out;

        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL); // mark for level
        vector<int> ivec;
        while(!q.empty()) {
            TreeNode *cur = q.front();
            q.pop();
            if (cur == NULL) {
                out.push_back(ivec);
                ivec.resize(0);
                if (q.size() > 0)
                    q.push(NULL);
            }
            else {
                ivec.push_back(cur->val);
                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
            }
        }
        return out;
    }
};

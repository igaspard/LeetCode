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
    vector<int> largestValues(TreeNode* root) {
        vector<int> rowmax;
        if (root==NULL)
            return rowmax;

        int max = INT_MIN;
        queue<TreeNode*> q;

        q.push(root);
        q.push(NULL);

        while(!q.empty()) {
            TreeNode *cur = q.front();
            q.pop();

            if (cur==NULL) {
                rowmax.push_back(max);
                max = INT_MIN;
                if(q.size() > 0) {
                    q.push(NULL);
                }
            }
            else {
                if (cur->val > max) max = cur->val;
                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
            }
        }
        return rowmax;
    }
};

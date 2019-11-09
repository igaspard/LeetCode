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
    int findBottomLeftValue(TreeNode* root) {

        if (root->left==NULL && root->right==NULL)
            return root->val;

        queue<TreeNode*> q;
        int LeftMost;

        q.push(root);
        q.push(NULL);

        while (!q.empty()) {
            TreeNode *cur = q.front();
            q.pop();

            if (cur == NULL) {
                if (q.size() > 0) {
                    TreeNode *leftMostNode = q.front();
                    LeftMost = leftMostNode->val;
                    q.push(NULL);
                }
            }
            else {
                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
            }
        }
        return LeftMost;
    }
};

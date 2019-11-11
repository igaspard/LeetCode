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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        if (root==NULL)
            return ans;
        
        queue<TreeNode*> cur, next;
        next.push(root);
        
        while(!next.empty()) {
            TreeNode *t = next.front();            
            while ( t!=NULL && !next.empty() ) {
                cur.push(t);                
                next.pop();
                t = next.front();
            }
            
            vector<int> level_ans;
            while (!cur.empty()) {
                TreeNode* c = cur.front(); cur.pop();
                level_ans.emplace_back(c->val);
                if (c->left != NULL)
                    next.push(c->left);
                if (c->right != NULL)
                    next.push(c->right);
            }
            double sum = 0.0;
            for(auto a: level_ans)
                sum += a;
            ans.emplace_back(sum/level_ans.size());
        }
        
        return ans;
        
    }
};

// Runtime: 28 ms, faster than 12.05% of C++ online submissions for Average of Levels in Binary Tree.
// Memory Usage: 22.2 MB, less than 33.33% of C++ online submissions for Average of Levels in Binary Tree.
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr)
            return {};
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()) {
            int level_size = q.size();
            vector<int> level;
            for (int i = 0; i < level_size; ++i) {
                TreeNode *tmp = q.front();
                q.pop();
                level.emplace_back(tmp->val);
                if(tmp->left != nullptr)
                    q.push(tmp->left);
                if(tmp->right != nullptr)
                    q.push(tmp->right);        
            }
            
            ans.emplace_back(level);
        }
        
        return ans;
    }
};

// BFS
// Time complexity: O(N)
// Space complexity: O(N)
// Runtime: 8 ms, faster than 49.79% of C++ online submissions for Binary Tree Level Order Traversal.
// Memory Usage: 12.6 MB, less than 72.56% of C++ online submissions for Binary Tree Level Order Traversal.

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

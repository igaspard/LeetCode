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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == nullptr) return ans;
        
        queue<TreeNode*> q;
        q.push(root);
        
        bool bReversed = false;
        
        while(!q.empty()) {
            int level_size = q.size();
            vector<int> level(level_size);
            for (int i = 0; i < level_size; ++i) {
                TreeNode *tmp = q.front();
                q.pop();
                if(bReversed)
                    level[level_size-i-1] = tmp->val;
                else
                    level[i] = tmp->val;
                
                if (tmp->left != nullptr) q.push(tmp->left);
                if (tmp->right != nullptr) q.push(tmp->right);
            }
            ans.emplace_back(level);
            bReversed = !bReversed;       
        }
        
        return ans;
    }
};

// Instead of reverse the level vector, assign as reverse order
// Runtime: 4 ms, faster than 80.24% of C++ online submissions for Binary Tree Zigzag Level Order Traversal.
// Memory Usage: 12.1 MB, less than 94.53% of C++ online submissions for Binary Tree Zigzag Level Order Traversal.

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == nullptr) return ans;
        
        queue<TreeNode*> q;
        q.push(root);
        
        bool bReversed = false;
        
        while(!q.empty()) {
            int level_size = q.size();
            vector<int> level;
            for (int i = 0; i < level_size; ++i) {
                TreeNode *tmp = q.front();
                q.pop();
                level.emplace_back(tmp->val);
                
                if (tmp->left != nullptr) q.push(tmp->left);
                if (tmp->right != nullptr) q.push(tmp->right);
            }
            if (bReversed) reverse(level.begin(), level.end());
            ans.emplace_back(level);
            bReversed = !bReversed;       
        }
        
        return ans;
    }
};

// Runtime: 8 ms, faster than 33.12% of C++ online submissions for Binary Tree Zigzag Level Order Traversal.
// Memory Usage: 12.1 MB, less than 83.30% of C++ online submissions for Binary Tree Zigzag Level Order Traversal.
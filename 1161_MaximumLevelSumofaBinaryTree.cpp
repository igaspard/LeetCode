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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        
        vector<int> sums;
        while(!q.empty()) {
            int level_size = q.size();
            long sum = 0;
            for (int i = 0; i < level_size; ++i) {
                TreeNode *tmp = q.front();
                q.pop();
                sum += tmp->val;
                
                if (tmp->left != nullptr) q.push(tmp->left);
                if (tmp->right != nullptr) q.push(tmp->right);
            }
            sums.emplace_back(sum);
        }
        
        auto it = max_element(sums.begin(), sums.end());
        return distance(sums.begin(), it) + 1;
    }
};

Runtime: 296 ms, faster than 67.08% of C++ online submissions for Maximum Level Sum of a Binary Tree.
Memory Usage: 107.5 MB, less than 39.40% of C++ online submissions for Maximum Level Sum of a Binary Tree.
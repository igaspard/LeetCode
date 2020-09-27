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
    int pathSum(TreeNode* root, int sum) {
        int ans = 0;
        vector<int> path;
        dfs(root, path, sum, ans);
        return ans;    
    }
    void dfs(TreeNode *root, vector<int> &path, const int target, int &ans) {
        if (root == nullptr) return;

        path.emplace_back(root->val);
        int sum = 0;
        for (auto it = path.rbegin(); it != path.rend(); ++it) {
            sum += *it;
            if (sum == target) ++ans;
        }

        dfs(root->left, path, target, ans);
        dfs(root->right, path, target, ans);

        path.pop_back();
    }
};

// DFS
// Runtime: 80 ms, faster than 13.36% of C++ online submissions for Path Sum III.
// Memory Usage: 16.5 MB, less than 44.59% of C++ online submissions for Path Sum III.

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
    int pathSum(TreeNode* root, int sum) {
        vector<int> path;
        
        return dfs(root, path, sum);
    }
    
    int dfs(TreeNode *root, vector<int> &path, int target) {
        if (root == nullptr) return 0;
        
        path.emplace_back(root->val);
        
        int sum = 0, cnt = 0;
        for(auto it = path.rbegin(); it != path.rend(); ++it) {
            sum += *it;
            if (sum == target) ++cnt;
        }

        cnt += dfs(root->left, path, target);
        cnt += dfs(root->right, path, target);
        
        path.pop_back();
        
        return cnt;
    }
};

// DFS
// Time complexity: O(N^2)
// Runtime: 76 ms, faster than 13.90% of C++ online submissions for Path Sum III.
// Memory Usage: 16.5 MB, less than 44.49% of C++ online submissions for Path Sum III.
class Solution {
   public:
    vector<vector<int>> ans;
    vector<vector<int>> pathSum(TreeNode *root, int sum) {
        vector<int> path;

        dfs(root, sum, path);
        return ans;
    }

    void dfs(TreeNode *root, int sum, vector<int> &path) {
        if (root == nullptr) return;

        path.emplace_back(root->val);
        if (sum == root->val && root->left == nullptr && root->right == nullptr)
            ans.emplace_back(path);
        else {
            dfs(root->left, sum - root->val, path);
            dfs(root->right, sum - root->val, path);
        }
        path.pop_back();
    }
};

// backtracking
// Runtime: 8 ms, faster than 83.61% of C++ online submissions for Path Sum II.
// Memory Usage: 20 MB, less than 61.81% of C++ online submissions for Path Sum II.

class Solution {
   public:
    vector<vector<int>> pathSum(TreeNode *root, int sum) {
        vector<vector<int>> ans;
        vector<int> path;

        dfs(root, sum, path, ans);
        return ans;
    }

    void dfs(TreeNode *root, int sum, vector<int> &path, vector<vector<int>> &ans) {
        if (root == nullptr) return;

        path.emplace_back(root->val);
        if (root->val == sum && root->left == nullptr && root->right == nullptr) {
            ans.emplace_back(path);
        } else {
            dfs(root->left, sum - root->val, path, ans);
            dfs(root->right, sum - root->val, path, ans);
        }
        path.pop_back();
    }
};

// DFS
// Runtime: 4 ms, faster than 99.82% of C++ online submissions for Path Sum II.
// Memory Usage: 19.7 MB, less than 97.71% of C++ online submissions for Path Sum II.
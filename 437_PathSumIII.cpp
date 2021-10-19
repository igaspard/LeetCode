class Solution {
public:
    int pathSum(TreeNode* root, int targetSum) {
        ans = 0;
        hash= {{0, 1}};
        
        helper(root, 0, targetSum);
        return ans;
    }
private:
    unordered_map<int, int> hash;
    int ans;
    
    void helper(TreeNode *root, int cur, int sum) {
        if (root == nullptr) return;
        
        cur += root->val;
        ans += hash[cur - sum];
        ++hash[cur];
        helper(root->left, cur, sum);
        helper(root->right, cur, sum);
        --hash[cur];
    }
};

// prefixSum + hash, similar to 560 Sub array sum equal to k
// Runtime: 12 ms, faster than 94.32% of C++ online submissions for Path Sum III.
// Memory Usage: 20.3 MB, less than 20.72% of C++ online submissions for Path Sum III.

class Solution {
   public:
    int pathSum(TreeNode *root, int targetSum) {
        if (root == nullptr) return 0;
        return dfs(root, targetSum) + pathSum(root->left, targetSum) + pathSum(root->right, targetSum);
    }

   private:
    int dfs(TreeNode *root, int sum) {
        if (root == nullptr) return 0;
        sum -= root->val;
        return (sum == 0 ? 1 : 0) + dfs(root->left, sum) + dfs(root->right, sum);
    }
};

// recursion
// Runtime: 12 ms, faster than 94.32% of C++ online submissions for Path Sum III.
// Memory Usage: 15.6 MB, less than 77.50% of C++ online submissions for Path Sum III.

class Solution {
   public:
    int pathSum(TreeNode *root, int sum) {
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
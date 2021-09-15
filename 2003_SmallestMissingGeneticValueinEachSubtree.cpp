class Solution {
   public:
    bool visited[100002] = {};
    vector<int> smallestMissingValueSubtree(vector<int>& parents, vector<int>& nums) {
        const int N = parents.size();
        vector<int> ans(N, 1);
        auto it = find(nums.begin(), nums.end(), 1);
        if (it == nums.end()) return ans;

        vector<vector<int>> children(N);
        for (int i = 1; i < N; ++i) children[parents[i]].push_back(i);

        int min = 1;
        for (int pos = it - nums.begin(); pos < N && pos != -1; pos = parents[pos]) {
            dfs(children, nums, pos);
            while (visited[min]) ++min;
            ans[pos] = min;
        }

        return ans;
    }

   private:
    void dfs(vector<vector<int>>& children, vector<int>& nums, int i) {
        if (visited[nums[i]] == false) {
            visited[nums[i]] = true;
            for (auto child : children[i]) dfs(children, nums, child);
        }
    }
};

// dfs on the tree path include value 1, other ans is 1
// Runtime: 379 ms, faster than 84.75% of C++ online submissions for Smallest Missing Genetic Value in Each
// Subtree. Memory Usage: 133.6 MB, less than 94.46% of C++ online submissions for Smallest Missing Genetic
// Value in Each Subtree.
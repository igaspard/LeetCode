class Solution {
   public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        N = nums.size();
        if (sum % k != 0) return false;
        if (N < k) return false;

        vector<bool> visited(N, false);
        return backtrack(nums, visited, 0, k, 0, sum / k);
    }

   private:
    int N;
    bool backtrack(vector<int>& nums, vector<bool>& visited, int curSum, int k, int idx, int targetSum) {
        if (k == 0) return true;

        if (curSum == targetSum) return backtrack(nums, visited, 0, k - 1, 0, targetSum);

        for (int i = idx; i < N; ++i) {
            if (!visited[i] && curSum + nums[i] <= targetSum) {
                visited[i] = true;
                if (backtrack(nums, visited, curSum + nums[i], k, i + 1, targetSum)) return true;

                visited[i] = false;
            }
        }

        return false;
    }
};

// backtrack
// Runtime: 4 ms, faster than 87.26% of C++ online submissions for Partition to K Equal Sum Subsets.
// Memory Usage: 8.9 MB, less than 96.68% of C++ online submissions for Partition to K Equal Sum Subsets.
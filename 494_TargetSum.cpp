class Solution {
   public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for (auto n : nums) sum += n;
        if (sum < target || (sum + target) % 2 == 1) return 0;

        return subsets(nums, (sum + target) / 2);
    }

    int subsets(vector<int>& nums, int sum) {
        const int N = nums.size();
        int dp[sum + 1];
        dp[0] = 1;
        for (int j = 1; j < sum + 1; ++j) dp[j] = 0;

        for (int i = 1; i < N + 1; ++i) {
            for (int j = sum; j >= 0; --j) {
                if (j >= nums[i - 1])
                    dp[j] = dp[j] + dp[j - nums[i - 1]];
                else
                    dp[j] = dp[j];
            }
        }

        return dp[sum];
    }
};

// dp 1D
// Runtime: 8 ms, faster than 89.61% of C++ online submissions for Target Sum.
// Memory Usage: 9 MB, less than 91.22% of C++ online submissions for Target Sum.

class Solution {
   public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for (auto n : nums) sum += n;
        if (sum < target || (sum + target) % 2 == 1) return 0;

        return subsets(nums, (sum + target) / 2);
    }

    int subsets(vector<int>& nums, int sum) {
        const int N = nums.size();
        int dp[N + 1][sum + 1];

        for (int i = 0; i < N + 1; ++i) {
            dp[i][0] = 1;
            for (int j = 1; j < sum + 1; ++j) {
                dp[i][j] = 0;
            }
        }

        for (int i = 1; i < N + 1; ++i) {
            for (int j = 0; j < sum + 1; ++j) {
                if (j >= nums[i - 1])
                    dp[i][j] = dp[i - 1][j] + dp[i - 1][j - nums[i - 1]];
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }

        return dp[N][sum];
    }
};

// dp 2D
// Runtime: 4 ms, faster than 98.77% of C++ online submissions for Target Sum.
// Memory Usage: 9.1 MB, less than 57.63% of C++ online submissions for Target Sum.

class Solution {
   public:
    unordered_map<string, int> memo;
    int findTargetSumWays(vector<int>& nums, int S) { return dp(nums, 0, S); }

    int dp(vector<int>& nums, int idx, int target) {
        if (idx == nums.size()) {
            if (target == 0) return 1;
            return 0;
        }

        string key = to_string(idx) + "," + to_string(target);
        if (memo.count(key) != 0) return memo[key];

        int ans = dp(nums, idx + 1, target - nums[idx]) + dp(nums, idx + 1, target + nums[idx]);
        memo[key] = ans;

        return ans;
    }
};

// recursive w/ memo top down
// Runtime: 564 ms, faster than 23.53% of C++ online submissions for Target Sum.
// Memory Usage: 89.9 MB, less than 5.03% of C++ online submissions for Target Sum.

class Solution {
   public:
    int ans = 0;
    int findTargetSumWays(vector<int>& nums, int S) {
        backtrack(nums, 0, S);
        return ans;
    }

    void backtrack(vector<int>& nums, int idx, int target) {
        if (idx == nums.size()) {
            if (target == 0) ++ans;
            return;
        }

        // try '+'
        target -= nums[idx];
        backtrack(nums, idx + 1, target);
        target += nums[idx];

        // try '-'
        target += nums[idx];
        backtrack(nums, idx + 1, target);
        target -= nums[idx];
    }
};

// backtrack
// time complexity: O(2^N)
// Runtime: 1928 ms, faster than 5.24% of C++ online submissions for Target Sum.
// Memory Usage: 8.9 MB, less than 91.22% of C++ online submissions for Target Sum.
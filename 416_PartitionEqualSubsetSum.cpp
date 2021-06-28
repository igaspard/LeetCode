class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (auto n : nums) sum += n;
        if (sum % 2 != 0) return false;

        const int N = nums.size();
        const int T = sum / 2;

        bool dp[T+1];
        // base cases
        dp[0] = true;
        for (int i = 1; i < T + 1; ++i) dp[i] = false;

        for (int i = 0; i < N; ++i)
          for (int j = T; j >= 0; --j)
            if (nums[i] <= j) dp[j] = dp[j] || dp[j - nums[i]];

        return dp[T];
    }
};

// use 0/1 Knapsack

class Solution {
   public:
    bool canPartition(vector<int> &nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 != 0) return false;

        const int N = nums.size();
        const int T = sum / 2;
        bool dp[T + 1];
        // if (target < 0 || idx == nums.size()) return false;
        for (int j = 1; j < T + 1; ++j) dp[j] = false;

        // if (target == 0) return true;
        dp[0] = true;

        for (int i = N - 1; i >= 0; --i) {
            for (int j = T; j >= 0; --j) {
                if (j < nums[i])
                    continue;
                else
                    dp[j] = dp[j] || dp[j - nums[i]];
            }
        }

        return dp[T];
    }
};

// 2D dp bottom up
// time complexity: O(NK)
// speed complexity: O(N), one rows of dp table
// Runtime: 76 ms, faster than 86.10% of C++ online submissions for Partition Equal Subset Sum.
// Memory Usage: 9.2 MB, less than 89.85% of C++ online submissions for Partition Equal Subset Sum.

class Solution {
   public:
    bool canPartition(vector<int> &nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 != 0) return false;

        const int N = nums.size();
        const int T = sum / 2;
        bool dp[2][T + 1];
        // if (target < 0 || idx == nums.size()) return false;
        for (int i = 0; i < 2; ++i)
            for (int j = 0; j < T + 1; ++j) dp[i][j] = false;

        // if (target == 0) return true;
        for (int i = 0; i < 2; ++i) dp[i][0] = true;

        for (int i = N - 1; i >= 0; --i) {
            for (int j = 1; j < T + 1; ++j) {
                if (j >= nums[i]) {  // whether to choose nums[i] or not
                    dp[i % 2][j] = dp[(i + 1) % 2][j] || dp[(i + 1) % 2][j - nums[i]];
                } else {
                    dp[i % 2][j] = dp[(i + 1) % 2][j];
                }
            }
        }

        return dp[0][T];
    }
};

// 2D dp bottom up
// time complexity: O(NK)
// speed complexity: O(2N), since we only need previous rows result, reduce the dp table into 2 rows
// Runtime: 88 ms, faster than 82.63% of C++ online submissions for Partition Equal Subset Sum.
// Memory Usage: 9 MB, less than 95.69% of C++ online submissions for Partition Equal Subset Sum.

class Solution {
   public:
    bool canPartition(vector<int> &nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 != 0) return false;

        const int N = nums.size();
        const int T = sum / 2;
        bool dp[N + 1][T + 1];
        // if (target < 0 || idx == nums.size()) return false;
        for (int i = 0; i < N + 1; ++i)
            for (int j = 0; j < T + 1; ++j) dp[i][j] = false;

        // if (target == 0) return true;
        for (int i = 0; i < N + 1; ++i) dp[i][0] = true;

        for (int i = N - 1; i >= 0; --i) {
            for (int j = 1; j < T + 1; ++j) {
                if (j >= nums[i]) {  // whehter choose nums[idx] or not
                    dp[i][j] = dp[i + 1][j] || dp[i + 1][j - nums[i]];
                } else {
                    dp[i][j] = dp[i + 1][j];
                }
            }
        }

        return dp[0][T];
    }
};

// 2D dp bottom up
// time complexity: O(NK)
// speed complexity: O(NK)
// Runtime: 100 ms, faster than 73.21% of C++ online submissions for Partition Equal Subset Sum.
// Memory Usage: 11.2 MB, less than 68.99% of C++ online submissions for Partition Equal Subset Sum.

class Solution {
   public:
    bool canPartition(vector<int> &nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 != 0) return false;

        N = nums.size();
        int T = sum / 2;
        vector<vector<int>> memo(N + 1, vector<int>(T + 1, -1));
        return dp(memo, nums, 0, T);
    }

   private:
    int N;
    bool dp(vector<vector<int>> &memo, vector<int> &nums, int idx, int target) {
        if (target == 0) return true;
        if (target < 0 || idx == nums.size()) return false;

        if (memo[idx][target] != -1) return memo[idx][target] == 1 ? true : false;

        bool ans = dp(memo, nums, idx + 1, target) ||            // not choose nums[idx]
                   dp(memo, nums, idx + 1, target - nums[idx]);  // choose nums[idx]

        memo[idx][target] = ans ? 1 : 0;

        return ans;
    }
};

// recursive w/ memo top down
// time complexity: O(NK) N number of numbers, K half sum of numbers
// space complexity: O(NK)
// Runtime: 84 ms, faster than 84.39% of C++ online submissions for Partition Equal Subset Sum.
// Memory Usage: 76 MB, less than 9.28% of C++ online submissions for Partition Equal Subset Sum.

class Solution {
   public:
    bool canPartition(vector<int> &nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 != 0) return false;

        return helper(nums, 0, sum / 2);
    }

    bool helper(vector<int> &nums, int idx, int target) {
        if (target == 0) return true;
        if (target < 0 || idx == nums.size()) return false;

        return helper(nums, idx + 1, target) ||            // not choose nums[idx]
               helper(nums, idx + 1, target - nums[idx]);  // choose nums[idx]
    }
};

// recursive
// time complexity: O(2^N)
// TLE
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        const int N = nums.size();
        const int SUM = std::accumulate(nums.begin(), nums.end(), 0);
        if (SUM < S) return 0;
        
        const int offset = SUM;
        vector<vector<int>> dp(N+1, vector<int>(SUM+offset+1, 0));
        dp[0][offset] = 1;
        
        for (int i = 0; i < N; ++i) {
            for (int j = nums[i]; j < 2 * SUM + 1; ++j) {
                if (dp[i][j]) {
                    dp[i+1][j-nums[i]] += dp[i][j];
                    dp[i+1][j+nums[i]] += dp[i][j];
                }
            }
        }
        
        return dp[N][S+offset];
    }
};

// ways to sum up to j using nums[0 ~ i]
// DP dp[i][j] = dp[i-1][j-nums[i]] + dp[i-1][j+nums[i]]

// Runtime: 20 ms, faster than 69.74% of C++ online submissions for Target Sum.
// Memory Usage: 22.3 MB, less than 37.29% of C++ online submissions for Target Sum.
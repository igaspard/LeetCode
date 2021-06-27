class Solution {
   public:
    int maxCoins(vector<int>& nums) {
        const int N = nums.size();
        vector<int> coins(N + 2);
        coins[0] = 1;
        coins[N + 1] = 1;
        for (int i = 0; i < N; ++i) coins[i + 1] = nums[i];

        // define dp[i][j] as the max coins nums(i..j)
        int dp[N + 2][N + 2];
        for (int i = 0; i < N + 2; ++i)
            for (int j = 0; j < N + 2; ++j) dp[i][j] = 0;

        for (int i = N; i >= 0; --i)
            for (int j = i + 1; j < N + 2; ++j)
                for (int k = i + 1; k < j; ++k)
                    dp[i][j] = max(dp[i][j], dp[i][k] + dp[k][j] + coins[i] * coins[k] * coins[j]);

        return dp[0][N + 1];
    }
};

// dp
// Runtime: 304 ms, faster than 89.91% of C++ online submissions for Burst Balloons.
// Memory Usage: 9.2 MB, less than 66.48% of C++ online submissions for Burst Balloons.

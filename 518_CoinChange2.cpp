class Solution {
public:
    int change(int amount, vector<int>& coins) {
        const int N = coins.size();
        int dp[amount+1];
        dp[0] = 1;
        for (int i = 1; i < amount + 1; ++i) dp[i] = 0;
        
        for (int i = 0; i < N; ++i)
            for (int j = 1; j < amount + 1; ++j)
                if (coins[i] <= j) dp[j] = dp[j] + dp[j-coins[i]];

        return dp[amount];
    }
};

// 1D dp
// Runtime: 12 ms, faster than 75.81% of C++ online submissions for Coin Change 2.
// Memory Usage: 7 MB, less than 93.10% of C++ online submissions for Coin Change 2.

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        const int N = coins.size();
        int dp[N+1][amount+1];
        for (int i = 0; i < N + 1; ++i) {
            for (int j = 0; j < amount + 1; ++j) {
                if (j == 0) dp[i][j] = 1;
                else dp[i][j] = 0;
            }
        }
        
        for (int i = 1; i < N + 1; ++i) {
            for (int j = 1; j < amount + 1; ++j) {
                if (coins[i-1] <= j) dp[i][j] = dp[i-1][j] + dp[i][j-coins[i-1]];
                else dp[i][j] = dp[i-1][j];
            }
        }
        
        return dp[N][amount];
    }
};

// 2D dp
// Runtime: 20 ms, faster than 53.21% of C++ online submissions for Coin Change 2.
// Memory Usage: 11.9 MB, less than 42.33% of C++ online submissions for Coin Change 2.
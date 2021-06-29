class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int dp[amount+1];
        dp[0] = 0;
        for (int i = 1; i < amount + 1; ++i) dp[i] = amount + 1;
        
        int ans = INT_MAX;
        for (int i = 1; i < amount + 1; ++i) {
            for (auto coin : coins) 
                if (i >= coin) dp[i] = min(dp[i], dp[i-coin]+1);
        }
        
        return dp[amount] == amount + 1 ? -1 : dp[amount];
    }
};
// dp use array instead of vector
// Runtime: 16 ms, faster than 99.87% of C++ online submissions for Coin Change.
// Memory Usage: 9.9 MB, less than 99.07% of C++ online submissions for Coin Change.

class Solution {
   public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;

        for (int i = 0; i < dp.size(); ++i) {
            for (auto coin : coins) {
                if (i - coin < 0) continue;
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }

        return dp[amount] == amount + 1 ? -1 : dp[amount];
    }
};

// dp 
// Time complexity: O(N*K) N = amount, K = number of coins
// Runtime: 64 ms, faster than 74.69% of C++ online submissions for Coin Change.
// Memory Usage: 14.5 MB, less than 23.90% of C++ online submissions for Coin Change.

class Solution {
   public:
    const int INIT_VALUE = -666;
    int coinChange(vector<int>& coins, int amount) {
        vector<int> memo(amount + 1, INIT_VALUE);

        return helper(coins, memo, amount);
    }

    int helper(vector<int>& coins, vector<int>& memo, int amount) {
        if (amount == 0) return 0;
        if (amount < 0) return -1;
        if (memo[amount] != INIT_VALUE) return memo[amount];

        int ans = INT_MAX;
        for (auto coin : coins) {
            int sub = helper(coins, memo, amount - coin);
            if (sub == -1) continue;
            ans = min(ans, sub + 1);
        }

        memo[amount] = (ans == INT_MAX) ? -1 : ans;
        return memo[amount];
    }
};

// recursive w/ memo top down
// Time complexity: O(N*K) N = amount, K = number of coins
// Space complexity: O(N)
// Runtime: 80 ms, faster than 54.52% of C++ online submissions for Coin Change.
// Memory Usage: 16 MB, less than 19.63% of C++ online submissions for Coin Change.

class Solution {
   public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) return 0;
        if (amount < 0) return -1;

        int ans = INT_MAX;
        for (auto coin : coins) {
            int sub = coinChange(coins, amount - coin);
            if (sub == -1) continue;
            ans = min(ans, sub + 1);
        }

        return ans == INT_MAX ? -1 : ans;
    }
};

// brute force recursive
// Time Limit Exceeded
// Time complexity: n^k * O(k) = O(kn^k) N = amount, k = number of coins
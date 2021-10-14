class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        
        for (int i = 1; i < dp.size(); ++i) 
            for (int x = 1; x * x <= i; ++x)
                dp[i] = min(dp[i], dp[i-x*x] + 1);
        
        return dp[n];
    }
};

// DP
// Runtime: 164 ms, faster than 59.21% of C++ online submissions for Perfect Squares.
// Memory Usage: 9.1 MB, less than 41.61% of C++ online submissions for Perfect Squares.
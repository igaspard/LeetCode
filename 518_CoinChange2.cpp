class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount+1, 0);
        dp[0] = 1;
         
        for (auto coin: coins) 
            for (int j = coin; j <= amount; ++j) 
                dp[j] += dp[j-coin];
            
        return dp[amount];    
    }
};

// Runtime: 8 ms, faster than 91.48% of C++ online submissions for Coin Change 2.
// Memory Usage: 7.4 MB, less than 59.56% of C++ online submissions for Coin Change 2.

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size()+1, vector<int>(amount+1, 0));
        dp[0][0] = 1;
        
        for (int i = 1; i <= coins.size(); ++i) 
            for (int j = 0; j <= amount; ++j) 
                dp[i][j] = dp[i-1][j] + (coins[i-1] <= j ? dp[i][j-coins[i-1]] : 0);
            
        return dp[coins.size()][amount];    
    }
};
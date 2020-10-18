class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;

        int low = prices[0];
        int ans = 0;
        for (int i = 1; i < prices.size(); ++i) {
            low = min(low, prices[i]);
            ans = max(ans, prices[i] - low);
        }
        return ans;
    }
};

// Runtime: 8 ms, faster than 97.15% of C++ online submissions for Best Time to Buy and Sell Stock.
// Memory Usage: 13 MB, less than 88.12% of C++ online submissions for Best Time to Buy and Sell Stock.

class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;

        int low = prices[0];
        int ans = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] > low) {
                int profit = prices[i] - low;
                ans = max(profit, ans);
            }
            low = min(prices[i], low);
        }
        return ans;
    }
};

// Runtime: 4 ms, faster than 98.18% of C++ online submissions for Best Time to Buy and Sell Stock.
// Memory Usage: 9.5 MB, less than 90.83% of C++ online submissions for Best Time to Buy and Sell Stock.

// O(n), S = O(1)
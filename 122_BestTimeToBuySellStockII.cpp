class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        for (int i = 1; i < prices.size(); ++i)
            if (prices[i] > prices[i - 1]) ans += prices[i] - prices[i - 1];

        return ans;
    }
};

// O(n), S = O(1)
// Runtime: 11 ms, faster than 20.19% of C++ online submissions for Best Time to Buy and Sell Stock II.
// Memory Usage: 13.1 MB, less than 7.04% of C++ online submissions for Best Time to Buy and Sell Stock II.

class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        int i = 0;
        int valley = prices[0];
        int peak = prices[0];
        int ans = 0;

        const int N = prices.size();
        while (i < N - 1) {
            while (i < N - 1 && prices[i] >= prices[i + 1]) ++i;
            valley = prices[i];

            while (i < N - 1 && prices[i] <= prices[i + 1]) ++i;
            peak = prices[i];
            ans += peak - valley;
        }

        return ans;
    }
};

// Find pair of valley & peak, sum it up
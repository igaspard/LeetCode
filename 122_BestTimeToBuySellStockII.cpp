class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        for(int i = 1; i < prices.size(); i++) {
            if (prices[i] > prices[i-1])
                ans += prices[i] - prices[i-1];
        }
        return ans;
    }
};

// Runtime: 12 ms, faster than 7.93% of C++ online submissions for Best Time to Buy and Sell Stock II.
// Memory Usage: 9.6 MB, less than 61.90% of C++ online submissions for Best Time to Buy and Sell Stock II.

// O(n), S = O(1)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = INT_MIN, pre_buy = 0, sell = 0, pre_sell = 0;
        for (auto p : prices) {
            pre_buy = buy;
            buy = max(pre_sell - p, buy);
            
            pre_sell = sell;
            sell = max(pre_buy + p, sell);
        }
        
        return sell;
    }
};

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Best Time to Buy and Sell Stock with Cooldown.
// Memory Usage: 11.2 MB, less than 49.73% of C++ online submissions for Best Time to Buy and Sell Stock with Cooldown.


class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        int hold = INT_MIN;
        int rest = 0;
        int sold = 0;

        for (auto price : prices) {
            int pre_sold = sold;
            sold = hold + price;
            hold = max(hold, rest - price);
            rest = max(rest, pre_sold);
        }

        return max(rest, sold);
    }
};

// Runtime: 4 ms, faster than 74.40% of C++ online submissions for Best Time to Buy and Sell Stock with
// Cooldown. Memory Usage: 8.6 MB, less than 92.59% of C++ online submissions for Best Time to Buy and Sell
// Stock with Cooldown.

// O(n), S = O(1)
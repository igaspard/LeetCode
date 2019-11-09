class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int hold = INT_MIN;
        int rest = 0;
        int sold = 0;
        
        for (auto price: prices) {
            int pre_sold = sold;
            sold = hold + price;
            hold = max(hold, rest-price);
            rest = max(rest, pre_sold);
        }
        
        return max(rest, sold);
    }
};

// Runtime: 4 ms, faster than 74.40% of C++ online submissions for Best Time to Buy and Sell Stock with Cooldown.
// Memory Usage: 8.6 MB, less than 92.59% of C++ online submissions for Best Time to Buy and Sell Stock with Cooldown.

// O(n), S = O(1)
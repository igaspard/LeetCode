class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int oneBuyOneSell = 0, twoBuyTwoSell = 0;
        int oneBuy = INT_MAX, twoBuy = INT_MAX;
        
        for (auto p : prices) {
            oneBuy = min(oneBuy, p);
            oneBuyOneSell = max(oneBuyOneSell, p - oneBuy);
            twoBuy = min(twoBuy, p - oneBuyOneSell);
            twoBuyTwoSell = max(twoBuyTwoSell, p - twoBuy);
        }
        
        return twoBuyTwoSell;
    }
};

// Similar to Buy & Sell Stocks I, record the lowest prices & max profit.

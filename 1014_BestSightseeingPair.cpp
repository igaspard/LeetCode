class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int ans = 0, pre = 0;
        for (auto v : values) {
            ans = max(ans, pre + v);
            pre = max(pre, v) - 1;
        }
        return ans;
    }
};

// Best to Buy & Sell Stock
// Runtime: 84 ms, faster than 20.57% of C++ online submissions for Best Sightseeing Pair.
// Memory Usage: 39.4 MB, less than 84.06% of C++ online submissions for Best Sightseeing Pair.
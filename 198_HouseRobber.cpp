class Solution {
   public:
    int rob(vector<int>& nums) {
        int pre = 0, cur = 0;

        for (auto num : nums) {
            int tmp = max(cur, pre + num);
            pre = cur;
            cur = tmp;
        }

        return cur;
    }
};

// DP dp[i] = max(dp[i-1], dp[i-2]+M(i)), dp(-1) = dp(0) = 0
// Time Complexity:O(n)
// Space Complexity = O(1)
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for House Robber.
// Memory Usage: 8 MB, less than 100.00% of C++ online submissions for House Robber.


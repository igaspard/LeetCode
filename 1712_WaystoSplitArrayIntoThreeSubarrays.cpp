class Solution {
   public:
    int waysToSplit(vector<int>& nums) {
        const int N = nums.size();
        vector<int> preSum(N + 1, 0);
        for (int i = 1; i <= N; ++i) preSum[i] = preSum[i - 1] + nums[i - 1];

        const int MOD = 1e9 + 7;
        int ans = 0;
        for (int i = 0; i < N - 2; ++i) {
            auto left = lower_bound(preSum.begin() + i + 2, preSum.end(), 2 * preSum[i + 1]);
            auto right =
                upper_bound(preSum.begin() + i + 2, preSum.end() - 1, (preSum[N] + preSum[i + 1]) / 2);
            if (left < right) ans = (ans + right - left) % MOD;
        }

        return ans;
    }
};

// prefix sum + binary search
// Runtime: 416 ms, faster than 5.98% of C++ online submissions for Ways to Split Array Into Three Subarrays.
// Memory Usage: 85 MB, less than 38.87% of C++ online submissions for Ways to Split Array Into Three
// Subarrays.

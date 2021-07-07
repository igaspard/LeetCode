class Solution {
   public:
    int lastStoneWeightII(vector<int>& stones) {
        const int N = stones.size();
        int sum = 0;
        for (auto s : stones) sum += s;
        const int W = sum / 2;

        bool dp[W + 1];
        dp[0] = true;
        for (int j = 1; j < W + 1; ++j) dp[j] = false;

        for (int i = 0; i < N; ++i)
            for (int j = W; j >= 0; --j)
                if (stones[i] <= j) dp[j] = dp[j] || dp[j - stones[i]];

        int sum1 = 0;
        for (int j = W; j >= 0; --j) {
            if (dp[j] == true) {
                sum1 = j;
                break;
            }
        }

        int sum2 = sum - sum1;
        return abs(sum1 - sum2);
    }
};

// DP 1D, this question is same as Minimum Subset Sum Difference
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Last Stone Weight II.
// Memory Usage: 7.8 MB, less than 95.83% of C++ online submissions for Last Stone Weight II.
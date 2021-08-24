class Solution {
   public:
    int lengthOfLIS(vector<int>& nums) {
        const int N = nums.size();
        vector<int> top(N, 0);

        int ans = 0;
        for (int i = 0; i < N; ++i) {
            int poker = nums[i];

            auto it = lower_bound(top.begin(), top.begin() + ans, poker);
            // if not found, create a new piles
            if (it == top.begin() + ans) ++ans;

            *it = poker;
        }

        return ans;
    }
};

// Use Solitaire to find the solution
// binary search
// time complexity: O(NlogN)
// Runtime: 4 ms, faster than 99.12% of C++ online submissions for Longest Increasing Subsequence.
// Memory Usage: 10.6 MB, less than 13.68% of C++ online submissions for Longest Increasing Subsequence.

class Solution {
   public:
    int lengthOfLIS(vector<int>& nums) {
        const int N = nums.size();
        // dp[i] define as the LIS end with nums[i], base cases dp[0] = 1 &
        vector<int> dp(N, 1);

        // state transfer
        for (int i = 1; i < N; ++i)
            for (int j = 0; j < i; ++j)
                if (nums[j] < nums[i]) dp[i] = max(dp[i], dp[j] + 1);

        // return max in the dp[i]
        return *max_element(dp.begin(), dp.end());
    }
};

// dp
// time complexity: O(N^2)
// space complexity: O(N)
// Runtime: 272 ms, faster than 31.97% of C++ online submissions for Longest Increasing Subsequence.
// Memory Usage: 10.5 MB, less than 61.26% of C++ online submissions for Longest Increasing Subsequence.
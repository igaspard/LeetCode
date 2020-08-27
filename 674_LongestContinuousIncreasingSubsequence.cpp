class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        const int N = nums.size();
        if (!N || N==1) return N;

        int ans = 1, pre = 1;
        for (int i = 1; i < N; ++i) {
            if(nums[i] > nums[i-1])
                ans = max(ans, ++pre);
            else
                pre = 1;
        }
            
        return ans;
    }
};

// DP
// Time complexity: O(N)
// Space complexity: O(1)
// Runtime: 24 ms, faster than 56.30% of C++ online submissions for Longest Continuous Increasing Subsequence.
// Memory Usage: 11.1 MB, less than 59.64% of C++ online submissions for Longest Continuous Increasing Subsequence.

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        const int N = nums.size();
        if (!N || N==1) return N;

        vector<int> dp(N, 1);
            
        int ans = 1;
        for (int i = 1; i < N; ++i) {
            if(nums[i] > nums[i-1]) {
                dp[i] = dp[i-1] + 1;
                ans = max(ans, dp[i]);
            }
        }
            
        return ans;
    }
};

// DP
// Time complexity: O(N)
// Space complexity: O(N)
// Runtime: 16 ms, faster than 97.39% of C++ online submissions for Longest Continuous Increasing Subsequence.
// Memory Usage: 11.5 MB, less than 5.07% of C++ online submissions for Longest Continuous Increasing Subsequence.
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int preSum = nums[0];
        int ans = preSum;
        for (int i = 1; i < nums.size(); ++i) {
            int curSum = preSum < 0 ? nums[i] : preSum + nums[i];
            preSum = curSum;
            ans = max(ans, preSum);
        }
        
        return ans;
    }
};

// DP, dp[i] = dp[i-1] < 0 ? nums[i] : dp[i-1] + nums[i]
// O(n), S = O(1)
// Runtime: 8 ms, faster than 71.25% of C++ online submissions for Maximum Subarray.
// Memory Usage: 9.3 MB, less than 79.41% of C++ online submissions for Maximum Subarray.

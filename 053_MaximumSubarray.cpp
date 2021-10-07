class Solution {
   public:
    int maxSubArray(vector<int>& nums) {
        int pre = nums[0], ans = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            int cur = max(nums[i], pre + nums[i]);
            ans = max(ans, cur);
            pre = cur;
        }

        return ans;
    }
};

// DP w/ compression
// Time complexity: O(N)
// space complexity: O(1)
// Runtime: 8 ms, faster than 52.74% of C++ online submissions for Maximum Subarray.
// Memory Usage: 13.5 MB, less than 5.72% of C++ online submissions for Maximum Subarray.
class Solution {
   public:
    int maxSubArray(vector<int>& nums) {
        const int N = nums.size();
        vector<int> dp(N);
        dp[0] = nums[0];

        for (int i = 1; i < N; ++i) dp[i] = max(nums[i], dp[i - 1] + nums[i]);

        return *max_element(dp.begin(), dp.end());
    }
};

// DP, when handle the subsqeuence or sub array define dp[i] as the max sub array include nums[i]
// choose previous plus itself or it self since we need contiguous subarray 
// Time complexity: O(N)
// space complexity: O(N)
// Runtime: 8 ms, faster than 52.74% of C++ online submissions for Maximum Subarray.
// Memory Usage: 13.5 MB, less than 5.72% of C++ online submissions for Maximum Subarray.

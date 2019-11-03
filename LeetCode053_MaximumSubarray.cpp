class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        const int n = nums.size();
        
        int curSum = nums[0];
        int preSum = nums[0];
        int ans = curSum;
        for(int i = 1; i < n; i++) {
            curSum = preSum < 0 ? nums[i] : nums[i] + preSum;
            ans = max(ans, curSum);
            preSum = curSum;
        }
        
        return ans;       
    }
};

// Runtime: 8 ms, faster than 71.25% of C++ online submissions for Maximum Subarray.
// Memory Usage: 9.3 MB, less than 79.41% of C++ online submissions for Maximum Subarray.
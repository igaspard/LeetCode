class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int total = 0, maxSum = nums[0], minSum = nums[0], curMax = 0, curMin = 0;
        for (auto n : nums) {
            curMax = max(curMax + n, n);
            maxSum = max(maxSum, curMax);
            curMin = min(curMin + n, n);
            minSum = min(minSum, curMin);
            total += n;
        }
        
        return maxSum > 0 ? max(maxSum, total - minSum) : maxSum;
    }
};

// DP
// Runtime: 60 ms, faster than 79.36% of C++ online submissions for Maximum Sum Circular Subarray.
// Memory Usage: 39.8 MB, less than 65.02% of C++ online submissions for Maximum Sum Circular Subarray.
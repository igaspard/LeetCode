class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        const int N = nums.size();
        int i = 0;
        int sum = 0;
        int ans = INT_MAX;
        
        for (int j = 0; j < N; ++j) {
            sum += nums[j];
            while (sum >= s) {
                ans = min(ans, j-i+1);
                sum -= nums[i++];
            }
        }
        
        return (ans != INT_MAX) ? ans : 0;
    }
};

// Slide Window
// Time Complexity: O(N)
// Space Complexity: O(1)
// Runtime: 16 ms, faster than 85.50% of C++ online submissions for Minimum Size Subarray Sum.
// Memory Usage: 10.7 MB, less than 23.92% of C++ online submissions for Minimum Size Subarray Sum.
class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        unordered_map<int, int> hash = {{0, -1}};
        
        int ans = INT_MIN;
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            if (hash.count(sum-k))
                ans = max(ans, i - hash[sum-k]);
            if (!hash.count(sum))
                hash[sum] = i;
        }
        
        return ans == INT_MIN ? 0 : ans;
    }
};

// prefixSum
// Time complexity: O(N), Space Complexity: O(N)
// Runtime: 24 ms, faster than 98.71% of C++ online submissions for Maximum Size Subarray Sum Equals k.
// Memory Usage: 17.8 MB, less than 60.93% of C++ online submissions for Maximum Size Subarray Sum Equals k.
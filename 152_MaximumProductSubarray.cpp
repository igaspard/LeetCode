class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max_so_far = nums[0];
        int min_so_far = nums[0];
        int ans = max_so_far;
        
        for(int i = 1; i < nums.size(); i++) {
            int tmp_max = max(nums[i], max(max_so_far*nums[i], min_so_far*nums[i]));
            int tmp_min = min(nums[i], min(max_so_far*nums[i], min_so_far*nums[i]));
        
            max_so_far = tmp_max;
            min_so_far = tmp_min;
            ans = max(max_so_far, ans);
        }
        return ans;
    }
};

// DP use two DP to record max and min
// Time complexity: O(N)
// Space complexity: O(1)
// Runtime: 4 ms, faster than 98.55% of C++ online submissions for Maximum Product Subarray.
// Memory Usage: 11.8 MB, less than 84.38% of C++ online submissions for Maximum Product Subarray.
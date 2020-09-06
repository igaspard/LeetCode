class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int left = 0, right = 0, product = 1, ans = 0;
        
        while(right < nums.size()) {   
            product *= nums[right];
            
            while(product >= k && left <= right)
                product /= nums[left++];
            
            ans += right - left + 1;
            
            right++;
        }
        
        return ans;
    }
};

// Sliding Window, Two Points
// Time Complexity: O(N)
// Space Complexity: O(1)
// Runtime: 276 ms, faster than 82.20% of C++ online submissions for Subarray Product Less Than K.
// Memory Usage: 92 MB, less than 60.84% of C++ online submissions for Subarray Product Less Than K.
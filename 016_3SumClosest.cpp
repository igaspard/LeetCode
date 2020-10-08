class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        
        int min_diff = numeric_limits<int>::max();
        
        for (int i = 0; i < nums.size() - 2; ++i) {
            int left = i + 1, right = nums.size() - 1;
            while (left < right) {
                const int diff = target - nums[i] - nums[left] - nums[right];
                if (!diff) return target;
                
                if (abs(diff) < abs(min_diff)) min_diff = diff;
                
                if (diff > 0)
                    left++;
                else
                    right--;
            }
        }
        
        return target - min_diff;
    }
};


// Two Pointers follow up by 3Sum
// Time complexity: O(N^2)
// Space complexity: O(N)
// Runtime: 12 ms, faster than 91.02% of C++ online submissions for 3Sum Closest.
// Memory Usage: 10.2 MB, less than 6.17% of C++ online submissions for 3Sum Closest.
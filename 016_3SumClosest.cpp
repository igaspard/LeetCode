class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        
        int min_diff = numeric_limits<int>::max();
        
        for(int k = 0; k < nums.size() - 2; ++k) {
            int i = k + 1, j = nums.size() - 1;
            while(i < j) {
                const int diff = target - nums[k] - nums[i] - nums[j];
                
                if (!diff)
                    return target;
                
                if (abs(diff) < abs(min_diff))
                    min_diff = diff;
                
                if (diff > 0)
                    ++i;
                else
                    --j;
            }
        }
        
        return target - min_diff;
    }
};


// Two Pointers follow up by 3Sum
// Time complexity: O(N^2)
// Space complexity: O(N)
// Runtime: 28 ms, faster than 24.92% of C++ online submissions for 3Sum Closest.
// Memory Usage: 10 MB, less than 23.54% of C++ online submissions for 3Sum Closest.
class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        if (nums.empty() || (nums.size()==1 && nums[0]>=target))
            return 0;
        
        sort(nums.begin(), nums.end());
        
        int ans = 0;
        
        for (int k = 0; k < nums.size() - 2; ++k) {
            int i = k + 1, j = nums.size() - 1;
            while (i < j) {
                const int sum = nums[k] + nums[i] + nums[j];
                if (sum < target) {
                    ans += j - i;
                    ++i;
                }
                else
                    --j;
            }
        }
        
        return ans;
    }
};

// Two pointers
// Time complexity: O(N^2)
// Space complexity: O(1)
// Runtime: 16 ms, faster than 65.94% of C++ online submissions for 3Sum Smaller.
// Memory Usage: 13.1 MB, less than 56.49% of C++ online submissions for 3Sum Smaller.
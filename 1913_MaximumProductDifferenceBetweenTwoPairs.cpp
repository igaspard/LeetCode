class Solution {
   public:
    int maxProductDifference(vector<int>& nums) {
        nth_element(nums.begin(), nums.begin() + 2, nums.end());
        int mi = nums[0], mi2 = nums[1];

        nth_element(nums.begin(), nums.begin() + 2, nums.end(), greater<int>());
        int mx = nums[0], mx2 = nums[1];

        return mx * mx2 - mi * mi2;
    }
};

// quick select
// Runtime: 24 ms, faster than 33.33% of C++ online submissions for Maximum Product Difference Between Two Pairs.
// Memory Usage: 20.4 MB, less than 16.67% of C++ online submissions for Maximum Product Difference Between Two Pairs.

class Solution {
   public:
    int maxProductDifference(vector<int>& nums) {
        const int N = nums.size();
        sort(nums.begin(), nums.end());

        return nums[N - 1] * nums[N - 2] - nums[0] * nums[1];
    }
};

// sort
// Runtime: 28 ms, faster than 33.33% of C++ online submissions for Maximum Product Difference Between Two
// Pairs. Memory Usage: 20.5 MB, less than 16.67% of C++ online submissions for Maximum Product Difference
// Between Two Pairs.
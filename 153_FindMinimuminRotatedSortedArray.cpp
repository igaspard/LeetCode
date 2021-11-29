class Solution {
   public:
    int findMin(vector<int>& nums) { return helper(nums, 0, nums.size() - 1); }

   private:
    int helper(vector<int>& nums, int left, int right) {
        if (right - left < 2) return min(nums[left], nums[right]);  // base cases 1 or 2 elements
        // sorted, left one is the smallest
        if (nums[left] < nums[right]) return nums[left];

        int mid = left + (right - left) / 2;
        return min(helper(nums, left, mid - 1), helper(nums, mid, right));
    }
};

// recursive time complexity: O(log n)
// Runtime: 4 ms, faster than 60.79% of C++ online submissions for Find Minimum in Rotated Sorted Array.
// Memory Usage: 10.3 MB, less than 22.81% of C++ online submissions for Find Minimum in Rotated Sorted Array.

class Solution {
   public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            // if the nums[mid - 1] is bigger than the nums[mid], we find the minimum
            if (mid > 0 && nums[mid - 1] > nums[mid]) return nums[mid];
            // if nums[mid] is greater than the nums[right], search the right side
            if (nums[mid] > nums[right])
                left = mid + 1;
            else
                right = mid - 1;
        }

        return nums[left];
    }
};

// binary search
// time complexity: O(log n)
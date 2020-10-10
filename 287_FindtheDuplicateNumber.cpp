class Solution {
   public:
    int findDuplicate(vector<int>& nums) {
        int fast = nums[0], slow = nums[0];

        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (fast != slow);

        int start = nums[0];
        while (start != slow) {
            start = nums[start];
            slow = nums[slow];
        }

        return start;
    }
};

// Floyd's Tortoise and Hare (Fast and Slow algorithm)
// Where the cycle start is the Duplicate number
// Time complexity: O(N)
// Space complexity: O(1)
// Runtime: 4 ms, faster than 99.99% of C++ online submissions for Find the Duplicate Number.
// Memory Usage: 11.3 MB, less than 17.00% of C++ online submissions for Find the Duplicate Number.
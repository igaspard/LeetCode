class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        int slow = 0, fast = 1;
        while (fast < nums.size()) {
            if (nums[slow] != nums[fast]) {
                ++slow;
                nums[slow] = nums[fast];
            }
            ++fast;
        }

        return slow + 1;
    }
};

// fast & slow pointers
// Time complexity: O(N)
// Space complexity: O(1)
// Runtime: 4 ms, faster than 97.92% of C++ online submissions for Remove Duplicates from Sorted Array.
// Memory Usage: 13.7 MB, less than 19.94% of C++ online submissions for Remove Duplicates from Sorted Array.

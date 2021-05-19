class Solution {
   public:
    int removeDuplicates(vector<int>& nums) {
        int j = 1, cnt = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i - 1] == nums[i])
                ++cnt;
            else
                cnt = 1;

            if (cnt <= 2) nums[j++] = nums[i];
        }

        return j;
    }
};

// two pointers
// Runtime: 4 ms, faster than 86.32% of C++ online submissions for Remove Duplicates from Sorted Array II.
// Memory Usage: 10.9 MB, less than 25.81% of C++ online submissions for Remove Duplicates from Sorted Array
// II.

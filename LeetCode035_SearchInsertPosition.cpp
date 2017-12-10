class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int i = 0;
        while (target > nums[i] && i < nums.size()) {
            i++;
        }
        return i;
    }
};

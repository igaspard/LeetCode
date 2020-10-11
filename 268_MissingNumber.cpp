class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int i = 0;
        while (i < nums.size()) {
            if (nums[i] < nums.size() && nums[i] != i) {
                swap(nums, i, nums[i]);
            } else {
                ++i;
            }
        }
        
        for (i = 0; i < nums.size(); ++i) {
            if (nums[i] != i) 
                return i;
        }
       
        return nums.size();
    }
    
    void swap(vector<int> &nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
};

// Cyclic sorted
// Runtime: 36 ms, faster than 87.61% of C++ online submissions for Missing Number.
// Memory Usage: 18.3 MB, less than 5.05% of C++ online submissions for Missing Number.
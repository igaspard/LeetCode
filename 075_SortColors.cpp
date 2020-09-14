class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        for(int i = 0; i <= high;) {
            if (nums[i] == 0) 
                swap(nums, i++, low++);
            else if (nums[i] == 1)
                ++i;
            else
                 swap(nums, i, high--);
        }
    }
private:
    void swap(vector<int> &nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
};

// Two pointers, use low, high to divide into three group, 0, low, 1, high 2
// Runtime: 4 ms, faster than 58.20% of C++ online submissions for Sort Colors.
// Memory Usage: 8.6 MB, less than 9.25% of C++ online submissions for Sort Colors.
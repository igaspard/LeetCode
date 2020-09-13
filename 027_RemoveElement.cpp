class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0;
        while(i < nums.size()) {
            if (nums[i] == val)
                nums.erase(nums.begin()+i);
            else
                ++i;
        }
        
        return nums.size();
    }
};

// Runtime: 4 ms, faster than 66.48% of C++ online submissions for Remove Element.
// Memory Usage: 8.9 MB, less than 71.63% of C++ online submissions for Remove Element.
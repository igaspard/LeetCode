class Solution {
public:
    int minOperations(vector<int>& nums) {
        if (nums.size() == 1) return 0;
        
        int ans = 0;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] <= nums[i-1]) {
                int inc = nums[i-1] - nums[i] + 1;
                nums[i] = nums[i] + inc;
                ans += inc;
            }
        }
        
        return ans;
    }
};

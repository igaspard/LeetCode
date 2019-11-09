class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty())
            return 0;
        if (nums.size()==1)
            return nums[0];        
        
        int pre0 = 0;
        int cur0 = 0;
        int pre1 = 0;
        int cur1 = 0;
        
        for(int i = 0; i < nums.size(); i++) {
            if (i < nums.size()-1) {
                int money0 = max(cur0, pre0+nums[i]);
                pre0 = cur0;
                cur0 = money0;
            }
            if (i > 0) {
                int money1 = max(cur1, pre1+nums[i]);
                pre1 = cur1;
                cur1 = money1;    
            }
        }
        return max(cur0, cur1);
    }
};

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for House Robber II.
// Memory Usage: 8.6 MB, less than 91.43% of C++ online submissions for House Robber II.

// O(n), S = O(1)
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty())
            return 0;
                
        int pre = 0;
        int cur = 0;
        
        for(int i = 0; i < nums.size(); i++) {
            int money = max(cur, pre+nums[i]);
            pre = cur;
            cur = money;
        }
        return cur;
    }
};

// Runtime: 4 ms, faster than 56.62% of C++ online submissions for House Robber.
// Memory Usage: 8.5 MB, less than 100.00% of C++ online submissions for House Robber.

// O(n), S = O(1)
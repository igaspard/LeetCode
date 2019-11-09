class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        if (nums.empty())
            return 0;
        const int r = *max_element(nums.begin(), nums.end());
        vector<int> points(r+1, 0);
        for (auto num: nums)
            points[num] += num;
        
        return rob(points);
    }
    
    int rob(vector<int>& nums) {
        int pre = 0;
        int cur = 0;
        for (int i = 0; i < nums.size(); i++) {
            int rob = max(cur, pre + nums[i]);
            pre = cur;
            cur = rob;
        }
        return cur;
    }
};

// Runtime: 4 ms, faster than 98.98% of C++ online submissions for Delete and Earn.
// Memory Usage: 9 MB, less than 75.00% of C++ online submissions for Delete and Earn.

// O(n+r), S = O(r)
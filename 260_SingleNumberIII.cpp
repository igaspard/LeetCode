class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long xr = 0;
        for (auto n : nums) xr ^= n;
        // get the right most bit of the X ^ Y
        int mask = xr & (-xr);
        // using mask to divide into two groups
        int grp1 = 0, grp2 = 0;
        for (auto n : nums) {
            if (mask & n) grp1 ^= n;
            else grp2 ^= n;
        }
        
        return {grp1, grp2};
    }
};

// Time complexity: O(N), space complexity: O(1)
// XOR all the numbers we will get xr = X ^ Y
// then we get the right most bit of xr & (-x4), xr use long avoid overflow
// then we divide all the numbers into two groups by use the mask
// grp1 include X with other duplicate number, grp2 include Y with other duplicate number as well
// Runtime: 4 ms, faster than 98.65% of C++ online submissions for Single Number III.
// Memory Usage: 9.9 MB, less than 93.24% of C++ online submissions for Single Number III.

class Solution {
   public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int, int> hash;
        for (auto it : nums) hash[it]++;

        vector<int> ans;
        for (auto it : hash) {
            if (it.second == 1) ans.emplace_back(it.first);
        }

        return ans;
    }
};

// Runtime: 12 ms, faster than 34.22% of C++ online submissions for Single Number III.
// Memory Usage: 10.8 MB, less than 14.92% of C++ online submissions for Single Number III.

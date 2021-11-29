class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> pos; // val, idx
        
        for (int i = 0; i < nums.size(); ++i) {
            if (pos.count(nums[i]) != 0 && (i - pos[nums[i]]) <= k) return true;
            pos[nums[i]] = i;
        }
        
        return false;
    }
};

// hash, time complexity: O(N)
// Runtime: 140 ms, faster than 98.22% of C++ online submissions for Contains Duplicate II.
// Memory Usage: 77 MB, less than 76.26% of C++ online submissions for Contains Duplicate II.

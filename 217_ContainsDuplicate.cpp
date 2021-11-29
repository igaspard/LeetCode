class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        return unordered_set<int>(nums.begin(), nums.end()).size() < nums.size();
    }
};

// set, time complexity O(N)
// Runtime: 54 ms, faster than 14.38% of C++ online submissions for Contains Duplicate.
// Memory Usage: 20.3 MB, less than 36.17% of C++ online submissions for Contains Duplicate.

class Solution {
   public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> duplicate;
        for (auto n : nums) {
            if (duplicate.count(n) != 0) return true;

            duplicate.insert(n);
        }

        return false;
    }
};

// set, time complexity O(N)
// Runtime: 34 ms, faster than 54.45% of C++ online submissions for Contains Duplicate.
// Memory Usage: 20.3 MB, less than 47.88% of C++ online submissions for Contains Duplicate.

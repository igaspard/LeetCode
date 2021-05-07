class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int seenOnce = 0, seenTwice = 0;
        for (auto it : nums) {
            seenOnce = ~seenTwice & (seenOnce ^ it);
            seenTwice = ~seenOnce & (seenTwice ^ it);
        }
        
        return seenOnce;
    }
};

// Bit Manipulation
// Runtime: 8 ms, faster than 78.59% of C++ online submissions for Single Number II.
// Memory Usage: 9.4 MB, less than 84.85% of C++ online submissions for Single Number II.

class Solution {
   public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> hash;
        for (auto it : nums) hash[it]++;

        for (auto it : hash) {
            if (it.second == 1) return it.first;
        }

        return 0;
    }
};

// Hash map
// Runtime: 4 ms, faster than 98.07% of C++ online submissions for Single Number II.
// Memory Usage: 10 MB, less than 22.57% of C++ online submissions for Single Number II.

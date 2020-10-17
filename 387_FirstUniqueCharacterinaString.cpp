class Solution {
   public:
    int firstUniqChar(string s) {
        unordered_map<char, int> hash;
        for (auto c : s) hash[c]++;

        char target;
        for (auto entry : hash) {
            if (entry.second == 1) target = entry.first;
        }

        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == target) return i;
        }

        return -1;
    }
};

// Hash Table
// Runtime: 68 ms, faster than 70.65% of C++ online submissions for First Unique Character in a String.
// Memory Usage: 11 MB, less than 99.12% of C++ online submissions for First Unique Character in a String.
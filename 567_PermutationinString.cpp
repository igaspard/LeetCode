class Solution {
   public:
    bool checkInclusion(string s1, string s2) {
        int start = 0, matched = 0;
        unordered_map<char, int> hash;
        for (auto chr : s1) hash[chr]++;

        for (int end = 0; end < s2.length(); ++end) {
            char right = s2[end];
            if (hash.find(right) != hash.end()) {
                hash[right]--;
                if (hash[right] == 0) matched++;
            }

            if (matched == hash.size()) return true;

            if (end >= s1.length() - 1) {
                char left = s2[start++];
                if (hash.find(left) != hash.end()) {
                    if (hash[left] == 0) matched--;
                    hash[left]++;
                }
            }
        }

        return false;
    }
};

// Sliding Window & Hash Table
// Runtime: 28 ms, faster than 45.16% of C++ online submissions for Permutation in String.
// Memory Usage: 7.7 MB, less than 23.50% of C++ online submissions for Permutation in String.

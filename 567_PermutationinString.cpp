/*
 * @lc app=leetcode id=567 lang=cpp
 *
 * [567] Permutation in String
 */

// @lc code=start
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> need, window;
        for (auto ch : s1) need[ch]++;

        int left = 0, right = 0;
        int valid = 0;
        while (right < s2.length()) {
            char c = s2[right++];
            if (need.count(c)) {
                ++window[c];
                if (window[c] == need[c]) valid++;
            }

            while (right - left >= s1.length()) {
                if(valid == need.size()) return true;

                char d = s2[left++];
                if(need.count(d)) {
                    if (window[d] == need[d]) valid--;
                    window[d]--;
                }
            }
        }

        return false;
    }
};
// @lc code=end

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

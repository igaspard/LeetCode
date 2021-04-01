/*
 * @lc app=leetcode id=438 lang=cpp
 *
 * [438] Find All Anagrams in a String
 */

// @lc code=start
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char, int> need, window;
        for (auto ch : p) need[ch]++;

        int left = 0, right = 0, valid = 0;
        vector<int> ans;

        while(right < s.length()) {
            char c = s[right++];
            if (need.count(c)) {
                window[c]++;
                if (window[c] == need[c]) valid++;
            }

            while (right - left >= p.length()) {
                if (valid == need.size()) ans.emplace_back(left);

                char d = s[left++];
                if (need.count(d)) {
                    if (window[d] == need[d]) valid--;
                    window[d]--;
                }
            }
        }

        return ans;
    }
};
// @lc code=end

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        
        int start = 0, matched = 0;
        unordered_map<char, int> hash;
        for (auto chr : p) hash[chr]++;
        
        for (int end = 0; end < s.length(); ++end) {
            char right = s[end];
            if (hash.find(right) != hash.end()) {
                hash[right]--;
                if (hash[right] == 0) matched++;
            }
            
            if (matched == hash.size()) ans.emplace_back(start);
            
            if (end >= p.length() - 1) {
                char left = s[start++];
                if (hash.find(left) != hash.end()) {
                    if (hash[left] == 0) matched--;
                    hash[left]++;
                }
            }
        }
        
        return ans;
    }
};

// Runtime: 48 ms, faster than 36.85% of C++ online submissions for Find All Anagrams in a String.
// Memory Usage: 8.9 MB, less than 26.58% of C++ online submissions for Find All Anagrams in a String.
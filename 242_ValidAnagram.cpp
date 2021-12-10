class Solution {
   public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;

        int freq[26] = {0};
        for (int i = 0; i < s.length(); ++i) {
            ++freq[s[i] - 'a'];
            --freq[t[i] - 'a'];
        }

        for (int i = 0; i < 26; ++i)
            if (freq[i] != 0) return false;

        return true;
    }
};

// Hash
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Valid Anagram.
// Memory Usage: 7.4 MB, less than 43.76% of C++ online submissions for Valid Anagram.
class Solution {
   public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> freq;
        for (auto ch : s) ++freq[ch];

        for (auto ch : t) {
            --freq[ch];
            if (!freq[ch]) freq.erase(ch);
        }

        return freq.size() == 0 ? true : false;
    }
};

// Hash
// Runtime: 12 ms, faster than 52.48% of C++ online submissions for Valid Anagram.
// Memory Usage: 7.5 MB, less than 7.35% of C++ online submissions for Valid Anagram.

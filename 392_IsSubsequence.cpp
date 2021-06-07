class Solution {
public:
    bool isSubsequence(string s, string t) {
        unordered_map<char, vector<int>> hash;
        for (int i = 0; i < t.length(); ++i)
            hash[t[i]].emplace_back(i);

        int target = 0;
        for (auto ch : s) {
            if (hash.count(ch) == 0) return false;
            auto idx = hash[ch];
            auto next = lower_bound(idx.begin(), idx.end(), target);
            if (next == idx.end()) return false;
            target = *next + 1;
        }

        return true;
    }
};

// hash + binary search
// Runtime: 8 ms, faster than 11.76% of C++ online submissions for Is Subsequence.
// Memory Usage: 6.7 MB, less than 23.86% of C++ online submissions for Is Subsequence.

class Solution {
   public:
    bool isSubsequence(string s, string t) {
        int i = 0, j = 0;
        while (i < s.length() && j < t.length()) {
            if (s[i] == t[j]) ++i;
            ++j;
        }

        return i == s.length();
    }
};

// two points
// Runtime: 4 ms, faster than 28.12% of C++ online submissions for Is Subsequence.
// Memory Usage: 6.2 MB, less than 79.79% of C++ online submissions for Is Subsequence.

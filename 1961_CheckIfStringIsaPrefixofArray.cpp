class Solution {
   public:
    bool isPrefixString(string s, vector<string>& words) {
        const int N = s.length();
        int i = 0;
        for (auto w : words) {
            if ((N - i + 1) < w.length()) return false;
            for (auto ch : w) {
                if (s[i] == ch) {
                    ++i;
                } else {
                    return false;
                }
            }
            if (i == N) return true;
        }

        return false;
    }
};

// Runtime: 4 ms, faster than 75.00% of C++ online submissions for Check If String Is a Prefix of Array.
// Memory Usage: 13.9 MB, less than 25.00% of C++ online submissions for Check If String Is a Prefix of Array.
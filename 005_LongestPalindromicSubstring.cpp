class Solution {
   public:
    string longestPalindrome(string s) {
        string ans;
        for (int i = 0; i < s.length(); ++i) {
            string s1 = palindrome(s, i, i);
            string s2 = palindrome(s, i, i + 1);
            cout << "s1: " << s1 << ", s2: " << s2 << endl;
            ans = s1.length() > ans.length() ? s1 : ans;
            ans = s2.length() > ans.length() ? s2 : ans;
        }

        return ans;
    }

    string palindrome(string s, int l, int r) {
        while (l >= 0 && r < s.length() && s[l] == s[r]) {
            --l;
            ++r;
        }

        return s.substr(l + 1, r - l - 1);
    }
};

// two pointers
// Runtime: 136 ms, faster than 49.28% of C++ online submissions for Longest Palindromic Substring.
// Memory Usage: 247.3 MB, less than 14.74% of C++ online submissions for Longest Palindromic Substring.

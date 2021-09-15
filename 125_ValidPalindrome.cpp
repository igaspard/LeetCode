class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0, j = s.length() - 1;
        while (i <= j) {
            if (!isalnum(s[i])) ++i;
            else if (!isalnum(s[j])) --j;
            else if (tolower(s[i]) != tolower(s[j])) return false;
            else {
                ++i;
                --j;
            }
        }

        return true;
    }
};

// Runtime: 8 ms, faster than 51.57% of C++ online submissions for Valid Palindrome.
// Memory Usage: 7.4 MB, less than 44.03% of C++ online submissions for Valid Palindrome.
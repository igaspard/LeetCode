class Solution {
   public:
    string decodeString(string s) {
        int pos = 0;
        return helper(s, pos);
    }

   private:
    string helper(string s, int &pos) {
        string ans = "";
        while (pos < s.length() && s[pos] != ']') {
            if (isdigit(s[pos])) {
                int num = 0;
                while (pos < s.length() && isdigit(s[pos])) num = num * 10 + (s[pos++] - '0');
                ++pos;
                string remain = helper(s, pos);
                while (num--) ans += remain;
                ++pos;
            } else {
                ans.push_back(s[pos++]);
            }
        }

        return ans;
    }
};

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Decode String.
// Memory Usage: 6.6 MB, less than 49.82% of C++ online submissions for Decode String.

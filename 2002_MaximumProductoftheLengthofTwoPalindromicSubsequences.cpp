class Solution {
   public:
    int maxProduct(string s) {
        ans = 0;

        string s1 = "", s2 = "";
        backtrack(s, 0, s1, s2);

        return ans;
    }

   private:
    int ans;

    bool isPalin(string &s) {
        int i = 0, j = s.length() - 1;
        while (i < j) {
            if (s[i] != s[j]) return false;
            ++i;
            --j;
        }

        return true;
    }

    void backtrack(string &s, int i, string &s1, string &s2) {
        if (i == s.length()) {
            if (isPalin(s1) && isPalin(s2)) ans = max(ans, (int)s1.length() * (int)s2.length());
            return;
        }
        // include that char in first string
        s1.push_back(s[i]);
        backtrack(s, i + 1, s1, s2);
        s1.pop_back();
        // include that char in second string
        s2.push_back(s[i]);
        backtrack(s, i + 1, s1, s2);
        s2.pop_back();
        // exclude that char from both strings
        backtrack(s, i + 1, s1, s2);
    }
};

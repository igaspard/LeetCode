class Solution {
   public:
    int numDecodings(string s) {
        const int N = s.length();
        vector<int> dp(N + 1, 0);
        dp[0] = 1;  // "" equal 1
        if (s[0] == '0')
            dp[1] = 0;
        else
            dp[1] = 1;

        for (int i = 2; i < N + 1; ++i) {
            if (s[i - 1] != '0') dp[i] = dp[i - 1];  // number(s[1..n-1])
            // number(s[2..n-1]) if 10 ~ s[0][1] ~ 26
            int prefix = stoi(s.substr(i - 2, 2));
            if (prefix <= 26 && prefix >= 10) dp[i] += dp[i - 2];
        }

        return dp[N];
    }
};

// DP top down
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Decode Ways.
// Memory Usage: 6.1 MB, less than 69.43% of C++ online submissions for Decode Ways.

class Solution {
   public:
    int numDecodings(string s) {
        hash[""] = 1;

        return helper(s);
    }

   private:
    unordered_map<string, int> hash;

    int helper(const string &s) {
        if (hash.count(s)) return hash[s];
        if (s[0] == '0') return 0;
        if (s.length() == 1) return 1;
        // number(s[0..n-1]) = number(s[1..n-1]) + number(s[2..n-1]) if 10 ~ s[0][1] ~ 26
        int ans = helper(s.substr(1));
        int prefix = stoi(s.substr(0, 2));

        if (prefix <= 26) ans += helper(s.substr(2));

        hash[s] = ans;
        return hash[s];
    }
};

// Recursive with memorization
// Runtime: 4 ms, faster than 27.99% of C++ online submissions for Decode Ways.
// Memory Usage: 8.3 MB, less than 7.38% of C++ online submissions for Decode Ways.

class Solution {
   public:
    int numDecodings(string s) {
        if (s.empty() || s[0] == '0') return 0;
        if (s.length() == 1) return 1;

        int w1 = 1;
        int w2 = 1;
        for (int i = 1; i < s.length(); ++i) {
            int w = 0;
            if (!isValid(s[i]) && !isValid(s[i - 1], s[i])) return 0;
            if (isValid(s[i])) w = w1;
            if (isValid(s[i - 1], s[i])) w += w2;
            w2 = w1;
            w1 = w;
        }

        return w1;
    }

   private:
    bool isValid(const char c) { return c != '0'; }
    bool isValid(const char c1, const char c2) {
        const int num = (c1 - '0') * 10 + (c2 - '0');
        return num >= 10 && num <= 26;
    }
};

// DP
// Runtime: 4 ms, faster than 62.95% of C++ online submissions for Decode Ways.
// Memory Usage: 6.5 MB, less than 33.03% of C++ online submissions for Decode Ways.
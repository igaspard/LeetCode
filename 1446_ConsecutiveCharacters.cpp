class Solution {
public:
    int maxPower(string s) {
        int ans = 1, cnt = 1;
        for (int i = 1; i < s.length(); ++i) {
            if (s[i] == s[i-1]) {
                ++cnt;
                ans = max(ans, cnt);
            } else {
                cnt = 1;
            }
        }
        
        return ans;
    }
};

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Consecutive Characters.
// Memory Usage: 6.7 MB, less than 75.13% of C++ online submissions for Consecutive Characters.
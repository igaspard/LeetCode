class Solution {
public:
    string makeFancyString(string s) {
        if (s.length() <= 2) return s;
        
        string ans = s.substr(0, 2);
        for (int i = 2; i < s.length(); ++i) {
            auto N = ans.length();
            if (s[i] == ans[N-1] && s[i] == ans[N-2]) continue;
            else ans.push_back(s[i]);
        }
        return ans;
    }
};

// Runtime: 140 ms, faster than 16.67% of C++ online submissions for Delete Characters to Make Fancy String.
// Memory Usage: 41.2 MB, less than 16.67% of C++ online submissions for Delete Characters to Make Fancy String.

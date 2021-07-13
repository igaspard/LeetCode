class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<pair<int, int>> v(26, {-1, -1});
        
        const int N = s.length();
        
        for (int i = 0; i < N; ++i) {
            int idx = s[i] - 'a';
            if (v[idx].first == -1) v[idx].first = i;
            else v[idx].second = i;
        }
        
        int ans = 0;
        for (auto c : v) {
            if (c.second != -1) {
                unordered_set<char> st;
                for (int i = c.first + 1; i < c.second; ++i) st.insert(s[i]);
                ans += st.size();
            }
        }
        
        return ans;
    }
};

Runtime: 544 ms, faster than 45.45% of C++ online submissions for Unique Length-3 Palindromic Subsequences.
Memory Usage: 13 MB, less than 81.82% of C++ online submissions for Unique Length-3 Palindromic Subsequences.

class Solution {
public:
    const int K = 3;
    int countPalindromicSubsequence(string s) {
        ans.clear();
        string t = ""; 
        printSubsequence(s, t);
        return ans.size();
    }
private:
    unordered_set<string> ans;
    void printSubsequence(string s, string t) {
        if (s.empty()) {
            if (t.size() == 3 && t[0] == t[2]) ans.insert(t);
            return;
        }

        printSubsequence(s.substr(1), t + s[0]);

        printSubsequence(s.substr(1), t);
    }
};

// TLE
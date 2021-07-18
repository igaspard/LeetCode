class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        const int N = s.length();
        const int M = t.length();
        
        if (M > N) return isOneEditDistance(t, s);
        
        for (int i = 0; i < M; ++i) {
            if (s[i] != t[i]) {
                if (N == M) return s.substr(i+1) == t.substr(i+1);
                else return s.substr(i+1) == t.substr(i);
            }
        }
        
        return N == M + 1;
    }
};

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for One Edit Distance.
// Memory Usage: 6.6 MB, less than 30.05% of C++ online submissions for One Edit Distance.

class Solution {
   public:
    bool isOneEditDistance(string s, string t) {
        const int N = s.length();
        const int M = t.length();
        if (abs(N - M) > 1) return false;

        if (s.empty() && t.empty())
            return false;
        else if (s.empty() || t.empty())
            return true;
        else if (N == 1 && M == 1 && s[0] != t[0])
            return true;

        if (s[0] == t[0]) return isOneEditDistance(s.substr(1), t.substr(1));
        if (s.back() == t.back()) return isOneEditDistance(s.substr(0, N - 1), t.substr(0, M - 1));

        return false;
    }
};

// recursion
// Runtime: 52 ms, faster than 5.12% of C++ online submissions for One Edit Distance.
// Memory Usage: 196.8 MB, less than 5.12% of C++ online submissions for One Edit Distance.
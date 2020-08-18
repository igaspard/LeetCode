class Solution {
public:
    int numDecodings(string s) {
        if(s.empty() || s[0] == '0') return 0;
        if(s.length() == 1) return 1;
        
        int w1 = 1;
        int w2 = 1;
        for(int i = 1; i < s.length(); ++i) {
            int w = 0;
            if (!isValid(s[i]) && !isValid(s[i-1], s[i])) return 0;
            if (isValid(s[i])) w = w1;
            if (isValid(s[i-1], s[i])) w += w2;
            w2 = w1;
            w1 = w;
        }
     
        return w1;
    }
private:
    bool isValid(const char c) { return c != '0'; }
    bool isValid(const char c1, const char c2) {
        const int num = (c1-'0')*10 + (c2-'0');
        return num >= 10 && num <= 26;
    }
};

// DP
// Runtime: 4 ms, faster than 62.95% of C++ online submissions for Decode Ways.
// Memory Usage: 6.5 MB, less than 33.03% of C++ online submissions for Decode Ways.

class Solution {
public:
    int numDecodings(string s) {
        
        m_ways[""] = 1;
        
        return ways(s);
    }
    
    int ways(const string& s) {
        if(m_ways.count(s)) return m_ways[s];
        if(s[0] == '0') return 0;
        if(s.length()==1) return 1;
        
        int w = ways(s.substr(1));
        const int prefix = stoi(s.substr(0, 2));
        
        if (prefix <= 26)
            w += ways(s.substr(2));
        
        m_ways[s] = w;
        return w;
    }
    
    unordered_map<string, int> m_ways;
};

// Recursive
// Runtime: 24 ms, faster than 5.02% of C++ online submissions for Decode Ways.
// Memory Usage: 14.2 MB, less than 10.49% of C++ online submissions for Decode Ways.
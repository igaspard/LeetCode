class Solution {
public:
    int countGoodSubstrings(string s) {
        if (s.length() < 3) return 0;
        int ans = 0;
        
        for (int i = 0; i < s.length() - 2; ++i) {
            unordered_set<char> cset;
            bool isGoodstr = true;
            for (int j = i; j < i + 3; ++j) {
                
                if (cset.count(s[j]) == 0)
                    cset.insert(s[j]);
                else {
                    isGoodstr = false;
                    break;
                }
            }
            if (isGoodstr) ++ans;
        }
        
        return ans;
    }
    
};

// set
// Runtime: 16 ms, faster than 8.46% of C++ online submissions for Substrings of Size Three with Distinct Characters.
// Memory Usage: 8.9 MB, less than 5.01% of C++ online submissions for Substrings of Size Three with Distinct Characters.

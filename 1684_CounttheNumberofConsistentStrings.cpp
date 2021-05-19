class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_map<char, int> freq;
        for (auto ch : allowed) ++freq[ch];
        
        int ans = 0;
        for (auto word : words) {
            bool matched = true;
            for (auto ch : word) {
                if (freq.count(ch) == 0) {
                    matched = false;
                    break;
                }
            }
            if (matched) ++ans;
        }
        
        return ans;
    }
};

// Hash
// Runtime: 64 ms, faster than 31.52% of C++ online submissions for Count the Number of Consistent Strings.
// Memory Usage: 30.2 MB, less than 16.50% of C++ online submissions for Count the Number of Consistent Strings.


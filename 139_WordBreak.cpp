class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.size()+1);
        dp[0] = true;
        
        size_t maxLen =  0;
        for (auto word: wordDict)
            maxLen = std::max(maxLen, word.length());
        
        for(int i = 0; i < dp.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (i-j > maxLen)
                    continue;
                if(dp[j] && wordSet.count(s.substr(j, i-j))) {
                    dp[i] = true;
                    break;
                }
            }
        }
            
        return dp[s.size()];
    }
};

// DP array means whether we can break the word at that position.
// Time complexity: O(n^2)
// Space complexity: O(n)
// Runtime: 4 ms, faster than 99.06% of C++ online submissions for Word Break.
// Memory Usage: 7.7 MB, less than 89.91% of C++ online submissions for Word Break.
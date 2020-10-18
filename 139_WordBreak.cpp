class Solution {
   public:
    bool wordBreak(string s, vector<string>& wordDict) {
        for (auto word : wordDict) mem[word] = true;

        return wordBreak(s);
    }

    bool wordBreak(string s) {
        if (mem.count(s)) return mem[s];

        for (int i = 1; i < s.length(); ++i) {
            const string left = s.substr(0, i);
            const string right = s.substr(i);

            if (mem.count(left) && mem[left] && wordBreak(right)) return mem[s] = true;
        }
        return mem[s] = false;
    }

   private:
    unordered_map<string, bool> mem;
};

// Recursive
// Runtime: 44 ms, faster than 15.50% of C++ online submissions for Word Break.
// Memory Usage: 20.3 MB, less than 5.66% of C++ online submissions for Word Break.

class Solution {
   public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.size() + 1);
        dp[0] = true;

        size_t maxLen = 0;
        for (auto word : wordDict) maxLen = std::max(maxLen, word.length());

        for (int i = 0; i < dp.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (i - j > maxLen) continue;
                if (dp[j] && wordSet.count(s.substr(j, i - j))) {
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
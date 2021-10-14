class TrieNode {
   public:
    vector<TrieNode*> children;
    bool isEnd;

    TrieNode() : children(26), isEnd(false) {}

    ~TrieNode() {
        for (auto child : children) delete child;
    }
};

class Solution {
   public:
    bool wordBreak(string s, vector<string>& wordDict) {
        root = new TrieNode();
        // build trie prefix tree
        for (auto word : wordDict) {
            auto cur = root;
            for (auto ch : word) {
                ch -= 'a';
                if (cur->children[ch] == nullptr) cur->children[ch] = new TrieNode();
                cur = cur->children[ch];
            }
            cur->isEnd = true;
        }

        N = s.length();
        vector<bool> visited(N, false);

        return dfs(s, 0, visited);
    }

   private:
    int N;
    TrieNode* root;

    bool dfs(string s, int idx, vector<bool>& visited) {
        if (idx == N) return true;
        if (visited[idx] == true) return false;

        visited[idx] = true;

        auto cur = root;
        while (idx < N && cur->children[s[idx] - 'a'] != nullptr) {
            cur = cur->children[s[idx] - 'a'];
            bool ret = false;
            if (cur->isEnd) {
                ret = dfs(s, idx + 1, visited);
                if (ret == true) return true;
            }
            ++idx;
        }
        return false;
    }
};

// trie + dfs travers trie tree
// Runtime: 3 ms, faster than 94.20% of C++ online submissions for Word Break.
// Memory Usage: 11.7 MB, less than 57.80% of C++ online submissions for Word Break.

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
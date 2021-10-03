class WordDictionary {
   public:
    WordDictionary() {}

    void addWord(string word) { dict[word.length()].emplace_back(word); }

    bool search(string word) {
        for (auto str : dict[word.length()])
            if (isEqual(str, word)) return true;
        return false;
    }

   private:
    unordered_map<int, vector<string>> dict;

    bool isEqual(string a, string b) {
        for (int i = 0; i < a.length(); ++i) {
            if (b[i] == '.') continue;
            if (a[i] != b[i]) return false;
        }
        return true;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */

// hash map for same length word dictionary
// Runtime: 83 ms, faster than 67.43% of C++ online submissions for Design Add and Search Words Data
// Structure. Memory Usage: 31.5 MB, less than 96.63% of C++ online submissions for Design Add and Search
// Words Data Structure.

class TrieNode {
   public:
    TrieNode* children[26];
    bool isEnd;
    TrieNode() {
        isEnd = false;
        memset(children, NULL, sizeof(children));
    }
};

class WordDictionary {
   public:
    /** Initialize your data structure here. */
    WordDictionary() { root = new TrieNode(); }

    void addWord(string word) {
        TrieNode* cur = root;
        for (auto ch : word) {
            ch -= 'a';
            if (cur->children[ch] == nullptr) cur->children[ch] = new TrieNode();
            cur = cur->children[ch];
        }
        cur->isEnd = true;
    }

    bool search(string word) { return dfs(root, word); }

   private:
    TrieNode* root;

    bool dfs(TrieNode* cur, string word) {
        for (int i = 0; i < word.length(); ++i) {
            char ch = word[i];
            if (ch == '.') {
                for (int j = 0; j < 26; ++j) {
                    if (cur->children[j] != nullptr)
                        if (dfs(cur->children[j], word.substr(i + 1))) return true;
                }
                return false;
            } else {
                ch -= 'a';
                if (cur->children[ch] == nullptr) return false;
                cur = cur->children[ch];
            }
        }

        return cur->isEnd;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */

// trie
// Runtime: 113 ms, faster than 41.98% of C++ online submissions for Design Add and Search Words Data
// Structure. Memory Usage: 43.7 MB, less than 56.54% of C++ online submissions for Design Add and Search
// Words Data Structure.
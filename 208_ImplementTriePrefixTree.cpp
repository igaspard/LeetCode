class Trie {
   public:
    Trie() { root = new TrieNode(); }

    void insert(string word) {
        TrieNode* cur = root;
        for (auto ch : word) {
            ch -= 'a';
            if (cur->children[ch] == nullptr) cur->children[ch] = new TrieNode();
            cur = cur->children[ch];
        }
        cur->isEnd = true;
    }

    bool search(string word) {
        TrieNode* cur = root;
        for (auto ch : word) {
            ch -= 'a';
            if (cur->children[ch] == nullptr) return false;
            cur = cur->children[ch];
        }

        return cur->isEnd;
    }

    bool startsWith(string prefix) {
        TrieNode* cur = root;
        for (auto ch : prefix) {
            ch -= 'a';
            if (cur->children[ch] == nullptr) return false;
            cur = cur->children[ch];
        }

        return true;
    }

   private:
    struct TrieNode {
        struct TrieNode* children[26];
        bool isEnd;
    };
    TrieNode* root;
};

// Runtime: 72 ms, faster than 51.29% of C++ online submissions for Implement Trie (Prefix Tree).
// Memory Usage: 45.1 MB, less than 46.37% of C++ online submissions for Implement Trie (Prefix Tree).

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

class Trie {
   public:
    /** Initialize your data structure here. */
    Trie() : children(26), isEnd(false) {}

    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie* node = this;
        for (auto ch : word) {
            ch -= 'a';
            if (node->children[ch] == nullptr) {
                node->children[ch] = new Trie();
            }
            node = node->children[ch];
        }

        node->isEnd = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie* node = this->searchPrefix(word);
        return node != nullptr && node->isEnd;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) { return this->searchPrefix(prefix) != nullptr; }

   private:
    bool isEnd;
    vector<Trie*> children;

    Trie* searchPrefix(string prefix) {
        Trie* node = this;
        for (auto ch : prefix) {
            ch -= 'a';
            if (node->children[ch] == nullptr) return nullptr;
            node = node->children[ch];
        }
        return node;
    }
};

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        const int num_words = words.size();
        const int word_len = words[0].length();
        if (s.length() < num_words * word_len) return ans;
        
        unordered_map<string, int> hash;
        for (auto word : words) hash[word]++;

        for (int i = 0; i <= s.length() - num_words * word_len; ++i) {
            unordered_map<string, int> matched;
            for (int j = 0; j < num_words; ++j) {
                const string word = s.substr(i + j * word_len, word_len);
                if (hash.find(word) == hash.end()) break;
                matched[word]++;
                if (matched[word] > hash[word]) break;
                if (j == num_words - 1) ans.emplace_back(i);
            }
        }

        return ans;
    }
};

// Sliding window & Hash Table
// Runtime: 428 ms, faster than 70.78% of C++ online submissions for Substring with Concatenation of All Words.
// Memory Usage: 25 MB, less than 46.01% of C++ online submissions for Substring with Concatenation of All Words.

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        const int num_words = words.size();
        const int word_len = words[0].length();
        if (s.length() < num_words * word_len) return ans;
        
        unordered_map<string, int> hash;
        for (auto word : words) hash[word]++;

        for (int i = 0; i <= s.length() - num_words * word_len; ++i) {
            unordered_map<string, int> matched;
            for (int j = 0; j < num_words; ++j) {
                const string word = s.substr(i + j * word_len, word_len);
                if (hash.find(word) == hash.end()) {
                    matched[word]++;
                } else {
                    break;
                }

                if (matched.size() == hash.size()) {
                    bool all_matched = true;
                    for (auto word : words) {
                        if (matched[word] != hash[word]) {
                            all_matched = false;
                            break;
                        }
                    }
                    if (all_matched) ans.emplace_back(i);
                }
            }
        }

        return ans;
    }
};

// Sliding window & Hash Table
// Runtime: 488 ms, faster than 58.93% of C++ online submissions for Substring with Concatenation of All Words.
// Memory Usage: 25 MB, less than 45.91% of C++ online submissions for Substring with Concatenation of All Words.
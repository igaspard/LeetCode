class Solution {
   public:
    bool areSentencesSimilar(vector<string>& sentence1, vector<string>& sentence2,
                             vector<vector<string>>& similarPairs) {
        if (sentence1.size() != sentence2.size()) return false;

        unordered_map<string, unordered_set<string>> set;
        for (auto pair : similarPairs) {
            set[pair[0]].insert(pair[1]);
            set[pair[1]].insert(pair[0]);
        }

        for (int i = 0; i < sentence1.size(); ++i) {
            if (sentence1[i] == sentence2[i]) continue;
            if (!set[sentence1[i]].count(sentence2[i])) return false;
        }

        return true;
    }
};

// Hash Table
// Runtime: 24 ms, faster than 15.41% of C++ online submissions for Sentence Similarity.
// Memory Usage: 12.5 MB, less than 5.27% of C++ online submissions for Sentence Similarity.
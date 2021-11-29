class Solution {
   public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        unordered_map<int, int> dicts;
        for (auto w : words) ++dicts[bitmask(w)];

        vector<int> ans;
        for (auto p : puzzles) {
            int firstChar = 1 << (p[0] - 'a');
            int cnt = dicts[firstChar];

            int mask = bitmask(p.substr(1));
            for (int submask = mask; submask; submask = (submask - 1) & mask)
                cnt += dicts[submask | firstChar];

            ans.emplace_back(cnt);
        }

        return ans;
    }

   private:
    int bitmask(const string& word) {
        int mask = 0;
        for (auto ch : word) mask |= 1 << (ch - 'a');
        return mask;
    }
};

// bitmask
// Runtime: 188 ms, faster than 76.61% of C++ online submissions for Number of Valid Words for Each Puzzle.
// Memory Usage: 47.9 MB, less than 52.75% of C++ online submissions for Number of Valid Words for Each Puzzle.

class Solution {
   public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        vector<unordered_set<char>> dicts;
        for (auto w : words) {
            unordered_set<char> dict;
            for (auto ch : w) dict.insert(ch);
            dicts.emplace_back(dict);
        }

        vector<int> ans;
        for (auto p : puzzles) {
            char firstChar = p[0];
            int cnt = 0;
            for (auto dict : dicts) {
                if (dict.count(firstChar) == 0) continue;
                bool bMatch = true;
                for (auto it : dict) {
                    if (p.find(it) == string::npos) {
                        bMatch = false;
                        break;
                    }
                }
                if (bMatch) ++cnt;
            }
            ans.emplace_back(cnt);
        }

        return ans;
    }
};

// TLE
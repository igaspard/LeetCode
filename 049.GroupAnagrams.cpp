class Solution {
   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if (strs.size() == 1) return {{strs[0]}};

        unordered_map<string, vector<string>> freqs;
        for (auto str : strs) freqs[countingSort(str)].emplace_back(str);

        vector<vector<string>> ans;
        for (auto& it : freqs) ans.emplace_back(it.second);

        return ans;
    }

   private:
    string countingSort(const string& str) {
        int freq[26] = {0};
        for (auto ch : str) ++freq[ch - 'a'];

        string sorted(str);
        int j = 0;
        for (int i = 0; i < 26; ++i) {
            while (freq[i]-- > 0) sorted[j++] = 'a' + i;
        }

        return sorted;
    }
};

// Hash with counting sort, time complexity O(N * L)
// Runtime: 16 ms, faster than 99.92% of C++ online submissions for Group Anagrams.
// Memory Usage: 19.5 MB, less than 83.60% of C++ online submissions for Group Anagrams.

class Solution {
   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> freqs;
        for (auto str : strs) {
            string tmp(str);
            sort(tmp.begin(), tmp.end());
            freqs[tmp].emplace_back(str);
        }

        vector<vector<string>> ans;
        for (auto& it : freqs) ans.emplace_back(it.second);

        return ans;
    }
};

// Hash with sorted strings, time complexity O(N * LlogL)
// Runtime: 32 ms, faster than 79.36% of C++ online submissions for Group Anagrams.
// Memory Usage: 19.4 MB, less than 83.60% of C++ online submissions for Group Anagrams.

class Solution {
   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        const int N = strs.size();
        int freq[N][26];
        for (int j = 0; j < N; ++j)
            for (int i = 0; i < 26; ++i) freq[j][i] = 0;
        for (int i = 0; i < N; ++i)
            for (auto ch : strs[i]) ++freq[i][ch - 'a'];

        vector<bool> used(N, false);
        vector<vector<string>> ans;
        for (int i = 0; i < N; ++i) {
            if (used[i]) continue;
            vector<string> grp;
            grp.emplace_back(strs[i]);
            used[i] = true;
            for (int j = i + 1; j < N; ++j) {
                if (used[j]) continue;
                if (strs[i].length() != strs[j].length()) continue;

                bool matched = true;
                for (int c = 0; c < 26; ++c) {
                    if (freq[i][c] != freq[j][c]) {
                        matched = false;
                        break;
                    }
                }

                if (matched) {
                    grp.emplace_back(strs[j]);
                    used[j] = true;
                }
            }
            ans.emplace_back(grp);
        }

        return ans;
    }
};

// Hash, time complexity: O(N^2)
// Runtime: 516 ms, faster than 5.06% of C++ online submissions for Group Anagrams.
// Memory Usage: 18.2 MB, less than 94.65% of C++ online submissions for Group Anagrams.

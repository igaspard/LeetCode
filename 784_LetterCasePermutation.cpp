class Solution {
   public:
    vector<string> letterCasePermutation(string S) {
        vector<string> ans;

        ans.emplace_back(S);

        for (int i = 0; i < S.length(); ++i) {
            if (isalpha(S[i])) {
                const int N = (int)ans.size();
                for (int j = 0; j < N; ++j) {
                    vector<char> tmp(ans[j].begin(), ans[j].end());
                    if (isupper(tmp[i]))
                        tmp[i] = tolower(tmp[i]);
                    else
                        tmp[i] = toupper(tmp[i]);

                    ans.emplace_back(string(tmp.begin(), tmp.end()));
                }
            }
        }

        return ans;
    }
};

// BFS
Runtime: 16 ms, faster than 42.92% of C++ online submissions for Letter Case Permutation.
Memory Usage: 10.5 MB, less than 5.83% of C++ online submissions for Letter Case Permutation.
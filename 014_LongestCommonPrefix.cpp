class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        if (strs.size() ==1) return strs[0];

        for (int i = 0; i < strs[0].length(); ++i) {
            for (int j = 1; j < strs.size(); j++) {
                if (strs[0][i] != strs[j][i]) {
                    return strs[0].substr(0, i);
                }
            }
        }

        return strs[0];
    }
};

// Time complexity: O(N)
// Space complexity: O(0)
// Runtime: 8 ms, faster than 74.10% of C++ online submissions for Longest Common Prefix.
// Memory Usage: 9.1 MB, less than 91.55% of C++ online submissions for Longest Common Prefix.
class Solution {
   public:
    int findTheLongestSubstring(string s) {
        char c_m[26] = {1, 0, 0, 0, 2, 0, 0, 0, 4, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 16, 0, 0, 0, 0, 0};
        // a: 1, e: 2, i: 4, o: 8, u: 16, other 0

        int mask = 0, ans = 0;
        unordered_map<int, int> idx{{0, -1}};
        for (int i = 0; i < s.length(); ++i) {
            mask ^= c_m[s[i] - 'a'];
            if (idx.count(mask) == 0) idx[mask] = i;  // record the first mask idx happened
            ans = max(ans, i - idx[mask]); // the largest idx difference is the answer
        }

        return ans;
    }
};

// bitmask + hash
// Runtime: 108 ms, faster than 65.38% of C++ online submissions for Find the Longest Substring Containing
// Vowels in Even Counts. Memory Usage: 16.3 MB, less than 39.49% of C++ online submissions for Find the
// Longest Substring Containing Vowels in Even Counts.
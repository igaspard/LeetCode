class Solution {
public:
    int characterReplacement(string s, int k) {
        int ans = 0, start = 0;
        int max_repeat_cnt = 0;
        unordered_map<char, int> hash;
        
        for (int end = 0; end < s.length(); ++end) {
            char right = s[end];
            hash[right]++;
            max_repeat_cnt = max(max_repeat_cnt, hash[right]);
            
            if (end - start + 1 - max_repeat_cnt > k) {
                char left = s[start];
                hash[left]--;
                start++;
            }
            ans = max(ans, end - start + 1);
        }
        return ans;
    }
};

// Sliding window & Hash table
// Runtime: 28 ms, faster than 52.24% of C++ online submissions for Longest Repeating Character Replacement.
// Memory Usage: 7.5 MB, less than 7.49% of C++ online submissions for Longest Repeating Character Replacement.

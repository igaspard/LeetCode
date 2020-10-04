class Solution {
   public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int ans = 0, start = 0;
        unordered_map<char, int> hash;

        for (int end = 0; end < s.length(); ++end) {
            hash[s[end]]++;

            while (hash.size() > 2) {
                char left = s[start];
                hash[left]--;
                if (!hash[left]) hash.erase(left);
                start++;
            }
            ans = max(ans, end - start + 1);
        }
        return ans;
    }
};

// Sliding Window & Hash Table
// Runtime: 28 ms, faster than 32.73% of C++ online submissions for Longest Substring with At Most Two
// Distinct Characters. Memory Usage: 8.3 MB, less than 15.46% of C++ online submissions for Longest Substring
// with At Most Two Distinct Characters.
class Solution {
   public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int ans = 0;
        int start = 0;
        unordered_map<char, int> hash;

        for (int end = 0; end < s.length(); ++end) {
            hash[s[end]]++;

            while (hash.size() > k) {
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
// Time Complexity: O(N)
// Runtime: 28 ms, faster than 68.11% of C++ online submissions for Longest Substring with At Most K Distinct
// Characters. Memory Usage: 8.5 MB, less than 13.33% of C++ online submissions for Longest Substring with At
// Most K Distinct Characters.
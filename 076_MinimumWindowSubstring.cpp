class Solution {
   public:
    string minWindow(string s, string t) {
        unordered_map<char, int> hash;
        for (auto chr : t) hash[chr]++;

        int start = 0, matched = 0;
        int min_len = s.length() + 1;
        string ans = "";
        for (int end = 0; end < s.length(); ++end) {
            char right = s[end];
            if (hash.find(right) != hash.end()) {
                hash[right]--;
                if (hash[right] == 0) matched++;
            }

            while (matched == hash.size()) {
                if (end - start + 1 < min_len) {
                    min_len = end - start + 1;
                    ans = s.substr(start, min_len);
                }

                char left = s[start++];
                if (hash.find(left) != hash.end()) {
                    if (hash[left] == 0) matched--;
                    hash[left]++;
                }
            }
        }

        return ans;
    }
};

// Sliding Window & Hash Table
// Runtime: 48 ms, faster than 53.27% of C++ online submissions for Minimum Window Substring.
// Memory Usage: 16.7 MB, less than 8.01% of C++ online submissions for Minimum Window Substring.
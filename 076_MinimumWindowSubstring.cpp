class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> hash, window;
        for(auto ch : t) ++hash[ch];
        
        int left = 0, right = 0, match = 0, min_len = INT_MAX;
        string ans = "";
        while (right < s.length()) {
            char c = s[right++];
            if (hash.count(c) != 0) {
                ++window[c];
                if (hash[c] == window[c]) ++match;
            }
            
            while (match == hash.size()) {
                if (right - left < min_len) {
                    min_len = right - left;
                    ans = s.substr(left, min_len);
                }
                
                char d = s[left++];
                if (hash.count(d) != 0) {
                    if (window[d] == hash[d]) --match;
                    --window[d];
                }
            }
        }
        
        return ans;
    }
};

// sliding window + hash
// Runtime: 20 ms, faster than 55.41% of C++ online submissions for Minimum Window Substring.
// Memory Usage: 16.5 MB, less than 14.18% of C++ online submissions for Minimum Window Substring.

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
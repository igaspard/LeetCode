class Solution {
public:
    int longestBeautifulSubstring(string word) {
        if (word.length() < 5) return 0;
    
        unordered_map<char, int> hash;
        int left = 0, right = 0;
        char last = 'a';
        int ans = 0;
        while (right < word.length()) {
            char c = word[right];
            if (c < last) {
                while (left < right) {
                    hash[word[left]]--;
                    if (!hash[word[left]]) hash.erase(word[left]);
                    ++left;
                }
            }

            hash[c]++;

            if (hash.size() == 5) {
                ans = max(ans, right - left+1);
            }
            ++right;
            last = c;
        }

        return ans;
    }
};
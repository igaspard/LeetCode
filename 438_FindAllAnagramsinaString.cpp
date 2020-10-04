class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        
        int start = 0, matched = 0;
        unordered_map<char, int> hash;
        for (auto chr : p) hash[chr]++;
        
        for (int end = 0; end < s.length(); ++end) {
            char right = s[end];
            if (hash.find(right) != hash.end()) {
                hash[right]--;
                if (hash[right] == 0) matched++;
            }
            
            if (matched == hash.size()) ans.emplace_back(start);
            
            if (end >= p.length() - 1) {
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

Runtime: 48 ms, faster than 36.85% of C++ online submissions for Find All Anagrams in a String.
Memory Usage: 8.9 MB, less than 26.58% of C++ online submissions for Find All Anagrams in a String.
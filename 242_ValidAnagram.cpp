class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        
        int matched = 0;
        unordered_map<char, int> hash;
        for (auto chr : s) hash[chr]++;
        
        for (auto chr : t) {
            if (hash.find(chr) != hash.end()) {
                hash[chr]--;
                if (hash[chr] == 0) matched++;
            }
        }
        
        return matched == hash.size() ? true : false;
    }
};

// Hash Table
// Runtime: 28 ms, faster than 54.09% of C++ online submissions for Valid Anagram.
// Memory Usage: 7.7 MB, less than 7.83% of C++ online submissions for Valid Anagram.
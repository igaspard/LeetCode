class Solution {
public:
    bool areOccurrencesEqual(string s) {
        unordered_map<char, int> freq;
        
        for (auto ch : s) ++freq[ch];
        
        auto first = freq.begin();
        int occurs = first->second;
        for (auto it : freq)
            if (it.second != occurs) return false;

        return true;
    }
};

// Runtime: 4 ms, faster than 80.00% of C++ online submissions for Check if All Characters Have Equal Number of Occurrences.
// Memory Usage: 6.7 MB, less than 80.00% of C++ online submissions for Check if All Characters Have Equal Number of Occurrences.
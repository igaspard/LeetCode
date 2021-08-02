class Solution {
   public:
    bool makeEqual(vector<string>& words) {
        unordered_map<char, int> hash;

        for (auto word : words)
            for (auto ch : word) ++hash[ch];

        const int N = words.size();

        for (auto it : hash)
            if (it.second % N != 0) return false;

        return true;
    }
};

// Greedy hash
// Runtime: 16 ms, faster than 66.67% of C++ online submissions for Redistribute Characters to Make All
// Strings Equal. Memory Usage: 12.4 MB, less than 33.33% of C++ online submissions for Redistribute
// Characters to Make All Strings Equal.

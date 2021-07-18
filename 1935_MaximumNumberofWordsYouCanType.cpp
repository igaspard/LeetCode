class Solution {
   public:
    int canBeTypedWords(string text, string brokenLetters) {
        unordered_set<char> dict;
        for (auto ch : brokenLetters) dict.insert(ch);

        istringstream input(text);
        string str;
        int ans = 0;
        while (input >> str) {
            bool broken = false;
            for (auto ch : str) {
                if (dict.count(ch) != 0) {
                    broken = true;
                    break;
                }
            }
            if (!broken) ++ans;
        }

        return ans;
    }
};

// string
// Runtime: 4 ms, faster than 66.67% of C++ online submissions for Maximum Number of Words You Can Type.
// Memory Usage: 6.8 MB, less than 83.33% of C++ online submissions for Maximum Number of Words You Can Type.
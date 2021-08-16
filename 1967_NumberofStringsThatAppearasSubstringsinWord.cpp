class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int ans = 0;
        for (auto pattern : patterns) 
            if (word.find(pattern) != string::npos) ++ans;
        
        return ans;
    }
};

// use find

class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int ans = 0;
        for (auto pattern : patterns) {
            bool matched = false;
            const int N = pattern.length();
            for (int i = 0; i < word.length(); ++i) {
                if (word[i] == pattern[0] && word.substr(i, N) == pattern) {
                    matched = true;
                    break;
                }
            }
            if (matched) ++ans;
        }
        
        return ans;
    }
};

// string
// Runtime: 8 ms, faster than 40.00% of C++ online submissions for Number of Strings That Appear as Substrings in Word.
// Memory Usage: 9.1 MB, less than 60.00% of C++ online submissions for Number of Strings That Appear as Substrings in Word.

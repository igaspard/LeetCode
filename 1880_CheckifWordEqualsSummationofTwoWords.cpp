class Solution {
public:
    int strToNum(const string str) {
        int ans = 0;
        for (auto s : str)
            ans = ans * 10 + (s - 'a');

        return ans;
    }
    
    bool isSumEqual(string firstWord, string secondWord, string targetWord) {
        int sum = strToNum(firstWord) + strToNum(secondWord);    
        int target = strToNum(targetWord);
        
        return sum == target;
    }
};

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Check if Word Equals Summation of Two Words.
// Memory Usage: 6 MB, less than 56.04% of C++ online submissions for Check if Word Equals Summation of Two Words.

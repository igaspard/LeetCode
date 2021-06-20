class Solution {
public:
    string largestOddNumber(string num) {
        string ans;
        for (int j = num.length() - 1; j >= 0; --j) {
            if ((num[j] - '0') % 2 == 1) return num.substr(0, j + 1);
        }
        
        return ans;
    }
};
// Greedy
// Runtime: 32 ms, faster than 40.00% of C++ online submissions for Largest Odd Number in String.
// Memory Usage: 15 MB, less than 20.00% of C++ online submissions for Largest Odd Number in String.
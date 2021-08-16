class Solution {
public:
    int minSwaps(string s) {
        const int N = s.length();
        int left = 0, right = N - 1;
        while(s[right] != '[') --right;
        
        int paired = 0, ans = 0;
        while (left < right) {
            char ch = s[left];
            if (paired == 0 && ch == ']') {
                s[left] = '[';
                s[right] = ']';
                ++ans;
                ++paired;
                while (right != 0 && s[right] == ']') --right;
            } else if (ch == '[') ++paired;
            else if (paired != 0 && ch ==']') --paired;
            
            ++left;
        }
        
        return ans;
    }
};

// If the number of closing brackets is ever larger, you need to make a swap.
// Swap it with the opening bracket closest to the end of s.
// Runtime: 112 ms, faster than 75.00% of C++ online submissions for Minimum Number of Swaps to Make the String Balanced.
// Memory Usage: 31.1 MB, less than 25.00% of C++ online submissions for Minimum Number of Swaps to Make the String Balanced.

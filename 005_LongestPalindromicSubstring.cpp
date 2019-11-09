
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
// brute force, O(n^3), exceed time limitation
class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty() || s.size() == 1) {
            return s;
        }

        int longest = 1, head = 0, tail = 0;
        for (int i = 0; i < s.size(); i++) {
            for (int j = i + 1; j < s.size(); j++) {
                bool bPalindrome = true;
                for (int h = i, t = j; h < t; h++, t--) {
                    if(s[h]!=s[t]) {
                        bPalindrome = false;
                        break;
                    }
                }
                if(bPalindrome) {
                    if ((j-i+1) > longest) {
                        longest = max(longest, j - i + 1);
                        head = i; tail = j;
                    }
                }
            }
        }
        return s.substr(head, longest);
    }
};

class DPSolution {
public:
    string longestPalindrome(string s) {
        int dp[s.size()][s.size()], left = 0, right = 0;
        int len = s.empty() ? 0 : 1;
        for (int i = 0; i < s.size(); i++) { // i means string length
            for (int j = 0; j < i; j++) { // j means position
                dp[j][i] = (s[i] == s[j] && (i-j<2 || dp[j+1][i-1]));
                if (dp[j][i] && i-j+1 > len) {
                    len = i-j+1;
                    left = j; right = i;
                }
            }
            dp[i][i] = 1;
        }
        return s.substr(left, len);
    }
};

int main(int argc, char const *argv[]) {
    DPSolution mysolution;
    cout<<"babad: "<<mysolution.longestPalindrome("babad")<<endl;
    cout<<"cbbd: "<<mysolution.longestPalindrome("cbbd")<<endl;
    cout<<"a: "<<mysolution.longestPalindrome("a")<<endl;
    cout<<"[]: "<<mysolution.longestPalindrome("")<<endl;
    cout<<"abcda: "<<mysolution.longestPalindrome("abcda")<<endl;
    return 0;
}

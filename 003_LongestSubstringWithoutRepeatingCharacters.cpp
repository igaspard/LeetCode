#include <iostream>
#include <string>
#include <set>
#include <algorithm>
using namespace std;

// Time: O(n^3)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max = 0;
        for(int i = 0; i < s.length(); i++) {
            set<char> cset;
            cset.insert(s[i]);
            for(int j = i+1; j < s.length(); j++) {
                set<char>::iterator it = cset.find(s[j]);
                if(it == cset.end())
                    cset.insert(s[j]);
                else
                    break;
            }
            if(cset.size() > max)
                max = cset.size();
        }
        return max;
    }
};

class SolutionSlidingWindow {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty())
            return 0;

        int i = 0, j = 1;
        set<char> cset;
        cset.insert(s[i]);
        set<char>::size_type len = cset.size();
        while (i < s.length() && j < s.length()) {
            auto it = cset.find(s[j]);
            if (it == cset.end()) {
                cset.insert(s[j++]);
                len = max(len, cset.size());
            } else {
                cset.erase(s[i++]);
            }
        }
        return len;
    }
};

int main(int argc, char const *argv[]) {

    SolutionSlidingWindow mysolution;
    cout<<"abcabcbb: "<<mysolution.lengthOfLongestSubstring("abcabcbb")<<endl;
    cout<<"bbbbb: "<<mysolution.lengthOfLongestSubstring("bbbbb")<<endl;
    cout<<"pwwkew: "<<mysolution.lengthOfLongestSubstring("pwwkew")<<endl;
    cout<<"au: "<<mysolution.lengthOfLongestSubstring("au")<<endl;
    cout<<"[]: "<<mysolution.lengthOfLongestSubstring("")<<endl;
    cout<<"a: "<<mysolution.lengthOfLongestSubstring("a")<<endl;
    return 0;
}

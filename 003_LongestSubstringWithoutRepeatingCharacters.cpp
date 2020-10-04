class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0, start = 0;
        unordered_map<char, int> hash;
        for (int end = 0; end < s.length(); ++end) {
            char right = s[end];
            if (hash.count(right)) {
        // this is tricky; in the current window, we will not have any 'rightChar' after its
        // previous index and if 'windowStart' is already ahead of the last index of 'rightChar',
        // we'll keep 'windowStart'
        // example "abba" wiil got wrong answer due to previous a index is ahead of start
                start = max(start, hash[right]+1); 
            }
            hash[right] = end;
            ans = max(ans, end - start + 1);
        }
        
        return ans;
    }
};

// Sliding Window & Hash Table
// Runtime: 32 ms, faster than 66.52% of C++ online submissions for Longest Substring Without Repeating Characters.
// Memory Usage: 8.5 MB, less than 65.29% of C++ online submissions for Longest Substring Without Repeating Characters.

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

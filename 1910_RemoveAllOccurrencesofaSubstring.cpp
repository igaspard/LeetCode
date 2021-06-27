class Solution {
public:
    string removeOccurrences(string s, string part) {
        const int N = part.length();

        int i = 0;
        while (s.length() >= N && i < s.length()) {
            string str = s.substr(i, N);
            if (str == part) {
                s.erase(i, N);
                i = 0;
            } else {
                ++i;
            }
        }

        return s;
    }
};

// Runtime: 12 ms, faster than 100.00% of C++ online submissions for Remove All Occurrences of a Substring.
// Memory Usage: 10.3 MB, less than 20.00% of C++ online submissions for Remove All Occurrences of a Substring.
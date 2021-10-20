class Solution {
public:
    string reverseWords(string s) {
        istringstream input(s);
        string tmp, ans;
        input >> ans;
        while (input >> tmp)
            ans = tmp + " " + ans;

        return ans;
    }
};

// Runtime: 4 ms, faster than 84.03% of C++ online submissions for Reverse Words in a String.
// Memory Usage: 20.9 MB, less than 18.79% of C++ online submissions for Reverse Words in a String.

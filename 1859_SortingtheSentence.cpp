class Solution {
public:
    string sortSentence(string s) {
        istringstream input(s);
        string str;
        unordered_map<int, string> hash;
        int cnt = 0;

        while (input >> str) {
            int idx = str.back() - '0';
            hash[idx] = str.substr(0, str.length()-1);
            ++cnt;
        }

        string ans;
        for (int i = 1; i <= cnt; ++i) {
            ans.append(hash[i]);
            if (i != cnt) ans.append(" ");
        }

        return ans;
    }
};

// Hash
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Sorting the Sentence.
// Memory Usage: 6.3 MB, less than 33.33% of C++ online submissions for Sorting the Sentence.
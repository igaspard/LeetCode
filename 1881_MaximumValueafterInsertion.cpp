class Solution {
public:
    string maxValue(string n, int x) {
        const int N = n.length();
        bool negative = n[0] == '-';
        for (int i = negative ? 1: 0; i < N; ++i) {
            int cur = n[i] - '0';
            if (!negative && x > cur) {
                n.insert(i, to_string(x));
                return n;
            } else if (negative && x < cur) {
                n.insert(i, to_string(x));
                return n;
            }
        }

        n.insert(N, to_string(x));

        return n;
    }
};


// Runtime: 88 ms, faster than 63.77% of C++ online submissions for Maximum Value after Insertion.
// Memory Usage: 31.9 MB, less than 92.13% of C++ online submissions for Maximum Value after Insertion.

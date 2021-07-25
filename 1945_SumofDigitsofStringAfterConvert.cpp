class Solution {
   public:
    int getLucky(string s, int k) {
        string t0 = "";
        for (char ch : s) t0 += to_string(ch - 'a' + 1);

        int t1 = 0;
        for (auto ch : t0) t1 += ch - '0';

        if (k == 1) return t1;

        int t2 = 0;
        while (--k > 0) {
            while (t1 != 0) {
                int remain = t1 % 10;
                t2 += remain;
                t1 /= 10;
            }
            t1 = t2;
            t2 = 0;
        }

        return t1;
    }
};

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Sum of Digits of String After Convert.
// Memory Usage: 6.4 MB, less than 33.33% of C++ online submissions for Sum of Digits of String After Convert.
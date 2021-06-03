class Solution {
public:
    bool checkZeroOnes(string s) {
        int zero_cnt = 0;
        int one_cnt = 0;
        int zero_mx = 0;
        int one_mx = 0;
        const int N = s.length();
        for (int i = 0; i < N; ++i) {
            if (s[i] == '1') {
                ++one_cnt;
                zero_mx = max(zero_mx, zero_cnt);
                zero_cnt = 0;
            }
            else if (s[i] == '0') {
                ++zero_cnt;
                one_mx = max(one_mx, one_cnt);
                one_cnt = 0;
            }
        }
        
        if (s[N-1] == '1') {
            one_mx = max(one_mx, one_cnt);
        } else {
            zero_mx = max(zero_mx, zero_cnt);
        }
        
        return one_mx > zero_mx;
    }
};

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Longer Contiguous Segments of Ones than Zeros.
// Memory Usage: 5.9 MB, less than 85.71% of C++ online submissions for Longer Contiguous Segments of Ones than Zeros.
class Solution {
public:
    int _diff(string str, bool ONE) {
        char ch = ONE ? '1' : '0';
        char other = ONE ? '0' : '1';
        int cnt = 0;
        for (int i = 0; i < str.length(); ++i) {
            if (i % 2 == 0) {
                if (str[i] != ch) ++cnt;
            } else {
                if (str[i] != other) ++cnt;
            }
        }
        return cnt / 2;
    }
    
    int minSwaps(string s) {
        int oneCnt = count(s.begin(), s.end(), '1');
        int zeroCnt = count(s.begin(), s.end(), '0');
        if (abs(oneCnt - zeroCnt) > 1) return -1;

        if (zeroCnt > oneCnt) return _diff(s, false);
        if (zeroCnt < oneCnt) return _diff(s, true);
        return min(_diff(s, true), _diff(s, false));
    }
};

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Minimum Number of Swaps to Make the Binary String Alternating.
// Memory Usage: 6.6 MB, less than 16.67% of C++ online submissions for Minimum Number of Swaps to Make the Binary String Alternating.

class Solution {
public:
    bool isAlternating(string str) {
        for (int i = 1; i < str.length(); ++i) 
            if (str[i-1] == str[i]) return false;

        return true;
    }
    
    int minSwaps(string s) {
        if (isAlternating(s)) return 0;
        string str = s;
        sort(str.begin(), str.end());
        cout << str << endl;
        int ans = numeric_limits<int>::max();
        do {
            if (isAlternating(str)) {
                int diff_cnt = 0;
                for (int i = 0; i < s.length(); ++i)
                    if (s[i] != str[i]) ++diff_cnt;
                cout << str << ": diff cnt: " << diff_cnt << endl;
                ans = min(ans, diff_cnt/2);
            }
        } while (next_permutation(str.begin(), str.end()));
        

        return ans == numeric_limits<int>::max() ? -1 : ans;
    }
};

// TLE
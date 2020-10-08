class Solution {
   public:
    bool backspaceCompare(string S, string T) {
        int i = S.length() - 1, j = T.length() - 1;

        while (i >= 0 || j >= 0) {
            int next_i = GetNextValidChar(S, i);
            int next_j = GetNextValidChar(T, j);

            if (next_i < 0 && next_j < 0) return true;

            if (next_i < 0 || next_j < 0) return false;

            if (S[next_i] != T[next_j]) return false;

            i = next_i - 1;
            j = next_j - 1;
        }

        return true;
    }

    int GetNextValidChar(const string str, int idx) {
        int backspace_cnt = 0;
        while (idx >= 0) {
            if (str[idx] == '#')
                ++backspace_cnt;
            else if (backspace_cnt > 0)
                --backspace_cnt;
            else
                break;
            --idx;
        }

        return idx;
    }
};

// Sliding Windows, starting from the end to find out the next valid character
// Runtime: 4 ms, faster than 52.35% of C++ online submissions for Backspace String Compare.
// Memory Usage: 6.9 MB, less than 5.35% of C++ online submissions for Backspace String Compare.

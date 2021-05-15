class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        const int M = box.size();
        const int N = box[0].size();
        vector<vector<char>> ans(N, vector<char>(M, '.'));
        for (int j = 0; j < M; ++j) {
            for (int i = 0; i < N; ++i) {
                if (box[j][i] == '*')
                    ans[i][M-1-j] = '*';
                else if (box[j][i] == '#')
                    ans[i][M-1-j] = '#';
            }
        }

        for (int j = N-2; j >= 0; --j) {
            for (int i = 0; i < M; ++i) {
                if (ans[j][i]=='#') {
                    int fall = j;
                    while (fall+1 < N && ans[fall+1][i] == '.')
                        fall++;
                    if (fall != j) {
                        ans[fall][i] = '#';
                        ans[j][i] = '.';
                    }
                }
            }
        }

        return ans;
    }
};

// Runtime: 272 ms, faster than 42.86% of C++ online submissions for Rotating the Box.
// Memory Usage: 52.4 MB, less than 100.00% of C++ online submissions for Rotating the Box.
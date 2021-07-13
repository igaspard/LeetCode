class Solution {
   public:
    int countTriples(int n) {
        vector<bool> square(n * n + 1, false);
        for (int i = 1; i <= n; ++i) square[i * i] = true;

        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            int i_square = i * i;
            for (int j = i; i_square + j * j <= n * n; ++j) {
                if (square[i_square + j * j]) ans += 2;
            }
        }
        return ans;
    }
};

// Runtime: 4 ms, faster than 100.00% of C++ online submissions for Count Square Sum Triples.
// Memory Usage: 6.7 MB, less than 75.00% of C++ online submissions for Count Square Sum Triples.

class Solution {
   public:
    int countTriples(int n) {
        int ans = 0;
        for (int i = 1; i < n; ++i) {
            int i_square = i * i;
            for (int j = 1; j < n; ++j) {
                int j_square = j * j;
                for (int k = 1; k <= n; ++k)
                    if (k * k == i_square + j_square) ++ans;
            }
        }

        return ans;
    }
};

// Runtime: 304 ms, faster than 25.00% of C++ online submissions for Count Square Sum Triples.
// Memory Usage: 6 MB, less than 75.00% of C++ online submissions for Count Square Sum Triples.
class Solution {
   public:
    vector<int> sortedSquares(vector<int>& A) {
        const int N = A.size();
        vector<int> ans(N);

        int left = 0, right = N - 1;
        int idx = N - 1;

        while (left <= right) {
            const int left_squeares = A[left] * A[left];
            const int right_squares = A[right] * A[right];

            if (left_squeares > right_squares) {
                ans[idx--] = left_squeares;
                left++;
            } else {
                ans[idx--] = right_squares;
                right--;
            }
        }

        return ans;
    }
};

// Two pointers
// Runtime: 48 ms, faster than 97.87% of C++ online submissions for Squares of a Sorted Array.
// Memory Usage: 26.2 MB, less than 38.34% of C++ online submissions for Squares of a Sorted Array.

class Solution {
   public:
    vector<int> sortedSquares(vector<int>& A) {
        int n = A.size();
        vector<int> ans;

        int i = n, j = -1;
        for (int k = 0; k < n; ++k) {
            if (A[k] < 0)
                j = k;
            else {
                i = k;
                break;
            }
        }
        while (j >= 0 && i < n) {
            int neg_square = A[j] * A[j];
            int pos_square = A[i] * A[i];

            if (pos_square < neg_square) {
                ans.emplace_back(pos_square);
                ++i;
            } else {
                ans.emplace_back(neg_square);
                j--;
            }
        }

        while (j >= 0) {
            ans.emplace_back(A[j] * A[j]);
            j--;
        }

        while (i < n) {
            ans.emplace_back(A[i] * A[i]);
            ++i;
        }

        return ans;
    }
};

// Runtime: 80 ms, faster than 66.84% of C++ online submissions for Squares of a Sorted Array.
// Memory Usage: 27.1 MB, less than 9.08% of C++ online submissions for Squares of a Sorted Array.
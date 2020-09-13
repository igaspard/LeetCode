class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        const int N = A.size();
        vector<int> ans(N);
        
        int idx = N - 1;
        int i = 0, j = N - 1;
        while (i<=j) {
          int left = A[i] * A[i];
          int right = A[j] * A[j];

          if (left > right) {
            ans[idx--] = left;
            ++i;
          } 
          else {
            ans[idx--] = right;
            --j;
          }
        }
        return ans;
    }
};

// Runtime: 88 ms, faster than 64.23% of C++ online submissions for Squares of a Sorted Array.
// Memory Usage: 25.8 MB, less than 77.76% of C++ online submissions for Squares of a Sorted Array.

class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        int n = A.size();
        vector<int> ans;

        int i = n, j = -1;
        for(int k = 0; k < n; ++k) {
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
          } 
          else {
            ans.emplace_back(neg_square);
            j--;
          }
        }

        while(j >= 0) {
          ans.emplace_back(A[j]*A[j]);
          j--;
        }

        while(i < n) {
          ans.emplace_back(A[i]*A[i]);
          ++i;
        }

        return ans;
    }
};

// Runtime: 80 ms, faster than 66.84% of C++ online submissions for Squares of a Sorted Array.
// Memory Usage: 27.1 MB, less than 9.08% of C++ online submissions for Squares of a Sorted Array.
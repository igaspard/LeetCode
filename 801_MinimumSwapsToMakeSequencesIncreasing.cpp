class Solution {
   public:
    int minSwap(vector<int>& A, vector<int>& B) {
        const int N = A.size();

        int keep0 = 0;
        int swap0 = 1;

        for (int i = 1; i < N; ++i) {
            int keep1 = INT_MAX, swap1 = INT_MAX;
            if (A[i] > A[i - 1] && B[i] > B[i - 1]) {
                keep1 = keep0;
                swap1 = swap0 + 1;
            }

            if (A[i] > B[i - 1] && B[i] > A[i - 1]) {
                swap1 = min(swap1, keep0 + 1);
                keep1 = min(keep1, swap0);
            }

            keep0 = keep1;
            swap0 = swap1;
        }

        return min(keep0, swap0);
    }
};

// DP, use two states
// Keep record min swap to make A0~Ai-1, B0~Bi-1 without swap Ai Bi
// Swap record min swap to make A0~Ai-1, B0~Bi-1 with swap Ai Bi
// Time complexity: O(N)
// Space complexity: O(1)
// Runtime: 16 ms, faster than 92.19% of C++ online submissions for Minimum Swaps To Make Sequences
// Increasing. Memory Usage: 14.5 MB, less than 16.35% of C++ online submissions for Minimum Swaps To Make
// Sequences Increasing.

class Solution {
   public:
    int minSwap(vector<int>& A, vector<int>& B) {
        const int N = A.size();

        vector<int> keep(N, INT_MAX);
        vector<int> swap(N, INT_MAX);

        keep[0] = 0;
        swap[0] = 1;

        for (int i = 1; i < N; ++i) {
            if (A[i] > A[i - 1] && B[i] > B[i - 1]) {
                // Good case, no swapping needed.
                keep[i] = keep[i - 1]; 
                // Swapped A[i - 1] / B[i - 1], swap A[i], B[i] as well
                swap[i] = swap[i - 1] + 1;
            }

            if (A[i] > B[i - 1] && B[i] > A[i - 1]) {
                // A[i - 1] / B[i - 1] weren't swapped.
                swap[i] = min(swap[i], keep[i - 1] + 1);
                // Swapped A[i - 1] / B[i - 1], no swap needed for A[i] / B[i]
                keep[i] = min(keep[i], swap[i - 1]);
            }
        }

        return min(keep.back(), swap.back());
    }
};

// DP,
// Time complexity: O(N)
// Space complexity: O(N)
// Runtime: 12 ms, faster than 99.28% of C++ online submissions for Minimum Swaps To Make Sequences
// Increasing. Memory Usage: 14.7 MB, less than 16.35% of C++ online submissions for Minimum Swaps To Make
// Sequences Increasing.
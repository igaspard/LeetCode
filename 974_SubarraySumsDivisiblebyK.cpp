class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        unordered_map<int, int> count = {{0, 1}};
        
        int ans = 0, prefixSum = 0;
        for(int i = 0; i < A.size(); ++i) {
            prefixSum += A[i];
            ans += count[(prefixSum % K + K) % K]; // might be negative, need 
            count[(prefixSum % K + K) % K]++;
        }
        
        return ans;
    }
};

// PrefixSum, HashMap similar to 560
// as the PrefixSum can be negative, taking modulo twice 
// Time complexity: O(N)
// Space complexity: O(K)
// Runtime: 108 ms, faster than 80.25% of C++ online submissions for Subarray Sums Divisible by K.
// Memory Usage: 31.9 MB, less than 55.50% of C++ online submissions for Subarray Sums Divisible by K.
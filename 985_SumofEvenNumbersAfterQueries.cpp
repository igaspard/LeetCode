class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
        vector<int> ans;
        int sumEven = 0;
        for(auto a:A) {
            if (a%2 == 0)
                sumEven += a;
        }
        for(auto query: queries) {
            int tmp = A[query[1]];
            A[query[1]] += query[0];
            if (tmp % 2 == 0) 
                sumEven -= tmp;
            if (A[query[1]] % 2 == 0)
                sumEven += A[query[1]];
            ans.emplace_back(sumEven);
        }
        
        return ans;
    }
};

// Time complexity: O(N+M)
// Space complexity: O(N)
// Runtime: 236 ms, faster than 55.85% of C++ online submissions for Sum of Even Numbers After Queries.
// Memory Usage: 50 MB, less than 8.75% of C++ online submissions for Sum of Even Numbers After Queries.
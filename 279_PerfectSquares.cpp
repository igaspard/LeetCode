class Solution {
public:
    int numSquares(int n) {
        vector<int> square_vector;

        for (int i = 1; i <= (int) sqrt(n); i++) 
            square_vector.emplace_back(i*i);
        
        vector<int> dp(n+1, 0);
        dp[0] = dp[1] = 1;
        
        for(int i = 2; i < dp.size(); i++) {
            int ans = n;
            for (int j = 0; j < square_vector.size(); j++) {
                if (i > square_vector[j]) {
                    ans = min(ans, dp[i-square_vector[j]]+1);
                }
                else if (i == square_vector[j]) {
                    ans = 1;
                    break;
                }
                else
                    break;
            }
            dp[i] = ans;
        }
        
        return dp.back();
    }
};

// DP
// Time complexity: O(N * square root of N)
// Scape complexity: O(N)
Runtime: 276 ms, faster than 38.14% of C++ online submissions for Perfect Squares.
Memory Usage: 9.6 MB, less than 21.09% of C++ online submissions for Perfect Squares.
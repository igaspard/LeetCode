class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int f1 = 0, f2 = 0;
        
        for (int i = 2; i <= cost.size(); ++i) { // i <= cost.size() because we need to climb to the n-th stairs
            int cur = min(f1 + cost[i-1], f2 + cost[i-2]);
            f2 = f1;
            f1 = cur;
        }
        
        return f1;
    }
};

// DP, min cost to climb to n-th stairs dp[n] = min(dp[n-1]+cost[n-1], dp[n-2]+cost[n-2])
// Runtime: 12 ms, faster than 60.31% of C++ online submissions for Min Cost Climbing Stairs.
// Memory Usage: 13.8 MB, less than 98.97% of C++ online submissions for Min Cost Climbing Stairs.

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int f1 = cost[0];
        int f2 = cost[1];
        
        for(int i = 2; i < cost.size(); i++) {
            int cur = cost[i] + min(f1, f2);
            f1 = f2;
            f2 = cur;
        }
        
        return min(f1, f2);
    }
};

// Runtime: 8 ms, faster than 60.19% of C++ online submissions for Min Cost Climbing Stairs.
// Memory Usage: 8.6 MB, less than 97.67% of C++ online submissions for Min Cost Climbing Stairs.

// O(n), S = (1)
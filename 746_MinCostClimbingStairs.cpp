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
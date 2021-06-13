class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<int> merged(3, 0);
        
        for (auto &s : triplets) {
            if (s[0] <= target[0] && s[1] <= target[1] && s[2] <= target[2]) {
                merged[0] = max(merged[0], s[0]);
                merged[1] = max(merged[1], s[1]);
                merged[2] = max(merged[2], s[2]);
            }
        }
        
        return merged == target;
    }
};

// Greedy
// Runtime: 456 ms, faster than 20.00% of C++ online submissions for Merge Triplets to Form Target Triplet.
// Memory Usage: 146.5 MB, less than 20.00% of C++ online submissions for Merge Triplets to Form Target Triplet.
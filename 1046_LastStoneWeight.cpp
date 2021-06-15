class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        while (stones.size() > 1) {
            nth_element(stones.begin(), stones.end()-1, stones.end());
            nth_element(stones.begin(), stones.end()-2, stones.end());
            
            int diff = stones.back() - stones[stones.size()-2];
            stones.pop_back();
            stones.pop_back();
            if (diff != 0) stones.emplace_back(diff);
        }
        
        return stones.empty() ? 0 : stones[0];
    }
};

// quick select
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Last Stone Weight.
// Memory Usage: 7.6 MB, less than 30.89% of C++ online submissions for Last Stone Weight.

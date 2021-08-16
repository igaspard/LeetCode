class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> maxHeap;
        int ans = 0;
        for (auto p : piles) {
            maxHeap.emplace(p);
            ans += p;
        }
        for (int i = 0; i < k; ++i) {
            auto cur = maxHeap.top();
            maxHeap.pop();
            ans -= cur;
            cur -= floor(cur / 2);
            maxHeap.emplace(cur);
            ans += cur;
        }
        
        return ans;
    }
};

// Runtime: 392 ms, faster than 100.00% of C++ online submissions for Remove Stones to Minimize the Total.
// Memory Usage: 104.9 MB, less than 11.11% of C++ online submissions for Remove Stones to Minimize the Total.
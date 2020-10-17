class KthLargest {
   public:
    priority_queue<int, vector<int>, greater<int>> minHeap;
    const int K;
    KthLargest(int k, vector<int>& nums) : K(k) {
        for (auto num : nums) minHeap.emplace(num);
    }

    int add(int val) {
        minHeap.emplace(val);

        while (minHeap.size() > K) minHeap.pop();

        return minHeap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */

// Heaps
// Runtime: 56 ms, faster than 96.00% of C++ online submissions for Kth Largest Element in a Stream.
// Memory Usage: 20.1 MB, less than 8.56% of C++ online submissions for Kth Largest Element in a Stream.
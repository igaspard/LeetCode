class MedianFinder {
   public:
    /** initialize your data structure here. */
    priority_queue<int, vector<int>, less<int> > maxHeap;     // containing first half of numbers (smaller)
    priority_queue<int, vector<int>, greater<int> > minHeap;  // containing second half of numbers (bigger)
    MedianFinder() {}

    void addNum(int num) {
        if (maxHeap.empty() || maxHeap.top() >= num)
            maxHeap.emplace(num);
        else
            minHeap.emplace(num);

        if (maxHeap.size() > minHeap.size() + 1) {
            minHeap.emplace(maxHeap.top());
            maxHeap.pop();
        } else if (maxHeap.size() < minHeap.size()) {
            maxHeap.emplace(minHeap.top());
            minHeap.pop();
        }
    }

    double findMedian() {
        if (maxHeap.size() == minHeap.size()) return (maxHeap.top() + minHeap.top()) / 2.0;

        return maxHeap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

// Two Heaps, max Heap keep the smaller half of numbers, min Heap keep the larger half ones
// Time Complex: O(logn)
// Space Complex: O(n)
// Runtime: 176 ms, faster than 94.56% of C++ online submissions for Find Median from Data Stream.
// Memory Usage: 47.1 MB, less than 5.83% of C++ online submissions for Find Median from Data Stream.
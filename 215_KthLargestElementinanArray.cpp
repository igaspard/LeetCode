class Solution {
   public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> minHeap;

        for (int i = 0; i < k; ++i) minHeap.emplace(nums[i]);

        for (int i = k; i < nums.size(); ++i) {
            if (nums[i] > minHeap.top()) {
                minHeap.pop();
                minHeap.emplace(nums[i]);
            }
        }

        return minHeap.top();
    }
};

// Heap
// Time complexity: O(nlogk)
// Space complexity: O(k)
// Runtime: 16 ms, faster than 90.17% of C++ online submissions for Kth Largest Element in an Array.
// Memory Usage: 10.4 MB, less than 13.21% of C++ online submissions for Kth Largest Element in an Array.

class Solution {
   public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> maxHeap;

        for (auto num : nums) maxHeap.emplace(num);

        int ans;
        for (int i = 0; i < k; ++i) {
            ans = maxHeap.top();
            maxHeap.pop();
        }

        return ans;
    }
};

// Heap
// Runtime: 16 ms, faster than 90.17% of C++ online submissions for Kth Largest Element in an Array.
// Memory Usage: 10.6 MB, less than 13.21% of C++ online submissions for Kth Largest Element in an Array.

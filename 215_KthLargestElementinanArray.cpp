class Solution {
   public:
    int findKthLargest(vector<int>& nums, int k) {
        // find k largest equal to N - K + 1 smallest
        return quick_select(nums, nums.size() - k + 1, 0, nums.size() - 1);
    }

   private:
    static int quick_select(vector<int>& nums, int K, int start, int end) {
        int p = partition(nums, start, end);

        if (p == K - 1) return nums[p];

        if (p > K - 1) return quick_select(nums, K, start, p - 1);

        return quick_select(nums, K, p + 1, end);
    }

    static int partition(vector<int>& nums, int low, int high) {
        if (low == high) return low;
        //
        srand(time(0));
        int pivotIndex = low + rand() % (high - low);
        swap(nums[pivotIndex], nums[high]);

        int pivot = nums[high];
        for (int i = low; i < high; ++i)
            if (nums[i] < pivot) swap(nums[low++], nums[i]);

        swap(nums[low], nums[high]);

        return low;
    }
};

// quick select + Randomized Partitioning
// worst case for Quicksort occurs when the partition procedure splits the N-length array into arrays of size
// ‘11’ and ‘N−1’ choosing the pivot randomly has the effect of rendering the worst-case very unlikely,
// particularly for large arrays. Runtime: 4 ms, faster than 98.13% of C++ online submissions for Kth Largest
// Element in an Array. Memory Usage: 10.1 MB, less than 56.70% of C++ online submissions for Kth Largest
// Element in an Array.

class Solution {
   public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for (auto num : nums) {
            minHeap.emplace(num);
            if (minHeap.size() > k) minHeap.pop();
        }

        return minHeap.top();
    }
};

// Heap, find K largest use minHeap
// Time complexity: O(nlogk)
// Space complexity: O(k)
// Runtime: 16 ms, faster than 90.17% of C++ online submissions for Kth Largest Element in an Array.
// Memory Usage: 10.4 MB, less than 13.21% of C++ online submissions for Kth Largest Element in an Array.
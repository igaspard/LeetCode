class SparseVector {
   public:
    SparseVector(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != 0) data[i] = nums[i];
        }
    }

    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        int ans = 0;
        for (auto entry : data) {
            int idx = entry.first;
            int v1 = entry.second;

            if (vec.data.count(idx)) ans += v1 * vec.data[idx];
        }

        return ans;
    }
    unordered_map<int, int> data;
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);

// Hash
// Runtime: 184 ms, faster than 61.23% of C++ online submissions for Dot Product of Two Sparse Vectors.
// Memory Usage: 168.5 MB, less than 61.23% of C++ online submissions for Dot Product of Two Sparse Vectors.
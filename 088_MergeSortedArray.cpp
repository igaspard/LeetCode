class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1, j = n - 1, k = m + n - 1;
        while (i >= 0 && j >= 0)
            nums1[k--] = (nums1[i] > nums2[j]) ? nums1[i--] : nums2[j--];
     
        if (n > 0)
            std::copy(nums2.begin(), nums2.begin()+j+1, nums1.begin());    
    }
};

// Two points
// Time complexity: O(m+n)
// Space complexity: O(1)
// Runtime: 4 ms, faster than 85.69% of C++ online submissions for Merge Sorted Array.
// Memory Usage: 9.2 MB, less than 38.35% of C++ online submissions for Merge Sorted Array.
class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int ans = 0, left = 0, right = 0;
        while (left <= right && left < nums1.size() && right < nums2.size()) {
            if (nums1[left] <= nums2[right]) {
                ans = max(ans, right-left);
                ++right;
            } else {
                ++left;
                if (left > right) ++right;
            }
        }

        return ans;
    }
};

// Two points 
// Time complexity O(m+n)
// Runtime: 148 ms, faster than 75.00% of C++ online submissions for Maximum Distance Between a Pair of Values.
// Memory Usage: 98.3 MB, less than 50.00% of C++ online submissions for Maximum Distance Between a Pair of Values.
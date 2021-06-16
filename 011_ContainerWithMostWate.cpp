class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int ans = 0;
        while (left < right) {
            ans = max(ans, (right - left) * min(height[left], height[right]));
            
            if (height[left] < height[right]) ++left;
            else --right;
        }
        
        return ans;
    }
};

// two pointers
// Runtime: 20 ms, faster than 65.65% of C++ online submissions for Container With Most Water.
// Memory Usage: 9.9 MB, less than 48.45% of C++ online submissions for Container With Most Water.

class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = 0;
        const int N = height.size();
        for (int i = 0; i < N - 1; ++i) {
            for (int j = i; j < N; ++j) {
                ans = max(ans, (j - i) * min(height[i], height[j]));
            }
        }
        
        return ans;
    }
};

// brute force, O(N^2)
// TLE
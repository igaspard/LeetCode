class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = 0;
        int l = 0; 
        int r = height.size() - 1;
        while (l < r) {
            int container = std::min(height[l], height[r]) * (r - l);
            ans = std::max(ans, container);
            
            if (height[l] < height[r]) l++;
            else r--;
        }
        
        return ans;
    }
};

// Runtime: 20 ms, faster than 65.65% of C++ online submissions for Container With Most Water.
// Memory Usage: 9.9 MB, less than 48.45% of C++ online submissions for Container With Most Water.
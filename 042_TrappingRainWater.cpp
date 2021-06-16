class Solution {
   public:
    int trap(vector<int>& height) {
        const int N = height.size();
        if (!N) return 0;
        
        int left = 0, right = N - 1;
        int left_mx = height[0], right_mx = height[N - 1];

        int ans = 0;
        while (left <= right) {
            left_mx = max(left_mx, height[left]);
            right_mx = max(right_mx, height[right]);

            if (left_mx < right_mx)
                ans += left_mx - height[left++];
            else
                ans += right_mx - height[right--];
        }

        return ans;
    }
};

// two pointer
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Trapping Rain Water.
// Memory Usage: 14.2 MB, less than 78.95% of C++ online submissions for Trapping Rain Water.

class Solution {
   public:
    int trap(vector<int>& height) {
        if (height.empty()) return 0;

        const int N = height.size();
        vector<int> left_max(N);
        left_max[0] = height[0];
        for (int i = 1; i < N; ++i) left_max[i] = max(left_max[i - 1], height[i]);

        vector<int> right_max(N);
        right_max[N - 1] = height[N - 1];
        for (int i = N - 2; i >= 0; --i) right_max[i] = max(right_max[i + 1], height[i]);

        int ans = 0;
        for (int i = 1; i < height.size() - 1; ++i) ans += min(left_max[i], right_max[i]) - height[i];
        return ans;
    }
};

// DP memories, precalculated the left and right max values
// Runtime: 8 ms, faster than 55.20% of C++ online submissions for Trapping Rain Water.
// Memory Usage: 14.3 MB, less than 40.90% of C++ online submissions for Trapping Rain Water.

class Solution {
   public:
    int trap(vector<int>& height) {
        if (height.empty()) return 0;

        int ans = 0;
        for (int i = 1; i < height.size() - 1; ++i) {
            int left_max = *max_element(height.begin(), height.begin() + i);
            int right_max = *max_element(height.begin() + i, height.end());
            int rain = min(left_max, right_max) - height[i];
            ans += rain >= 0 ? rain : 0;
        }
        return ans;
    }
};

// brute force, sum up the min of left and right max values
// time complexity: O(N^2)
// Runtime: 180 ms, faster than 5.03% of C++ online submissions for Trapping Rain Water.
// Memory Usage: 14.1 MB, less than 78.95% of C++ online submissions for Trapping Rain Water.
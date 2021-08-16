class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        const int N = nums.size();
        sort(nums.begin(), nums.end());
        int mid = N / 2;
        if (N % 2 == 1) ++mid;
        vector<int> ans(N);
        for (int i = 0, j = 0; i < mid; ++i, j+=2)
            ans[j] = nums[i];

        for (int i = mid, j = 1; i < N; ++i, j+=2)
            ans[j] = nums[i];
        
        return ans;
    }
};

// Runtime: 220 ms, faster than 23.08% of C++ online submissions for Array With Elements Not Equal to Average of Neighbors.
// Memory Usage: 121.7 MB, less than 7.69% of C++ online submissions for Array With Elements Not Equal to Average of Neighbors.
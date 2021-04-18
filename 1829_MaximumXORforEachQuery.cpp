class Solution {
   public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        vector<int> ans;
        const int N = (int)nums.size();
        const int max = pow(2, maximumBit) - 1;

        int local = nums[0] ^ max;
        ans.emplace_back(local);
        for (int i = 1; i < N; ++i) {
            local ^= nums[i];
            ans.emplace_back(local);
        }
        reverse(ans.begin(), ans.end());

        return ans;
    }
};

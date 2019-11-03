class NumArray {
public:
    NumArray(vector<int>& nums) {
        const int n = nums.size();
        if (n > 0) {
            sum = new int[n];
        
            sum[0] = nums[0];
            for(int i = 1; i < n; i++) {
                sum[i] = sum[i-1] + nums[i];
            }            
        }        
    }
    
    int sumRange(int i, int j) {
        if (i > 0)
            return sum[j] - sum[i-1];
        else
            return sum[j];
    }
    
private:
    int *sum;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */

// Runtime: 28 ms, faster than 93.36% of C++ online submissions for Range Sum Query - Immutable.
// Memory Usage: 17.2 MB, less than 96.55% of C++ online submissions for Range Sum Query - Immutable.

// O(n), S = O(n)
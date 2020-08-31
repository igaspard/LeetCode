class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ans;
        for(int i=0; i<=num; ++i)
            ans.emplace_back(hammingWeight(i));
        
        return ans;
    }
private:
     int hammingWeight(uint32_t n) {
        int ans = 0;
        while(n) {
            n &= (n-1);
            ans++;
        }
        
        return ans;
    }
};

// Runtime: 8 ms, faster than 72.37% of C++ online submissions for Counting Bits.
// Memory Usage: 8.4 MB, less than 39.63% of C++ online submissions for Counting Bits.

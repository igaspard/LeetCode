class Solution {
public:
    vector<int> memLeak(int memory1, int memory2) {
        int crash = 1;
        while (memory1 >= 0 && memory2 >= 0) {
            if (memory1 < memory2) {
                if (memory2 >= crash) memory2 -= crash++;
                else break;
            } else {
                if (memory1 >= crash) memory1 -= crash++;
                else break;
            }
        }

        vector<int> ans(3);
        ans[0] = crash;
        ans[1] = memory1;
        ans[2] = memory2;
        return ans;
            
    }
};

// Runtime: 4 ms, faster than 100.00% of C++ online submissions for Incremental Memory Leak.
// Memory Usage: 6.2 MB, less than 75.00% of C++ online submissions for Incremental Memory Leak.
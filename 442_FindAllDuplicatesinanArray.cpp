class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        for (auto n : nums) {
            if (nums[abs(n) - 1] > 0) nums[abs(n) - 1] = -nums[abs(n) - 1];
            else ans.emplace_back(abs(n));
        }
        
        return ans;
    }
};

// since the val of a vector<int> is in the range of 1 ~ n, we can use the value as index and 

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        bool duplicated[100000] = {};
        
        vector<int> ans;
        for (auto n : nums) {
            if(duplicated[n]) ans.emplace_back(n);
            else duplicated[n] = true;
        }
        
        return ans;
    }
};

// hash or set
// time complexity: O(n)
// speed complexity: O(n)
// Runtime: 44 ms, faster than 93.85% of C++ online submissions for Find All Duplicates in an Array.
// Memory Usage: 33.7 MB, less than 27.18% of C++ online submissions for Find All Duplicates in an Array.
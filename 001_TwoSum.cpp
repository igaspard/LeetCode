class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map = {{nums[0], 0}}; 
        for (int i = 1; i < nums.size(); i++) {
            auto it = map.find(target - nums[i]);
            if(it != map.end()) {                
                return {it->second, i};
            }
            else
                map[nums[i]] = i;
        }
        return {};
    }
};

/*
One-pass Hash Table
time complexity: O(n) traverse list once, each time takes O(1) (hash table)
space complexity: O(n)

Runtime: 8 ms, faster than 92.77% of C++ online submissions for Two Sum.
Memory Usage: 10.4 MB, less than 19.07% of C++ online submissions for Two Sum.
*/
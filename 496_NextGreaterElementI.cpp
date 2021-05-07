/*
 * @lc app=leetcode id=496 lang=cpp
 *
 * [496] Next Greater Element I
 */

// @lc code=start
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> s;
        unordered_map<int, int> hash; // record num w/ next greater
        for (auto num : nums2) {
            while(!s.empty() && num > s.top()) {
                hash[s.top()] = num;
                s.pop();
            }
            s.push(num);
        }

        vector<int> ans;
        for (auto num : nums1)
            ans.emplace_back(hash.count(num) ? hash[num] : -1);

        return ans;    
    }

};
// @lc code=end

// Monotonic Stack + Hash Table
// Time complexity: O(m+n), scan each vector once
// Space complexity: O(m+n), stack & hash used n spaces, out used m spaces
// Runtime: 4 ms, faster than 93.90% of C++ online submissions for Next Greater Element I.
// Memory Usage: 9 MB, less than 28.58% of C++ online submissions for Next Greater Element I.

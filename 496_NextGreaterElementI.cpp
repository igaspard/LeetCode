class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> hash;
        stack<int> s;
        for (int i = nums2.size() - 1; i >= 0; --i) {
            while (!s.empty() && s.top() <= nums2[i]) s.pop();
            hash[nums2[i]] = s.empty() ? -1 : s.top();
            s.push(nums2[i]);
        }
        
        vector<int> ans;
        for (auto n : nums1) ans.emplace_back(hash[n]);
        return ans;
    }
};

// Monotonic Stack + Hash Table
// Runtime: 5 ms, faster than 65.75% of C++ online submissions for Next Greater Element I.
// Memory Usage: 9 MB, less than 14.53% of C++ online submissions for Next Greater Element I.

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

// Monotonic Stack + Hash Table
// Time complexity: O(m+n), scan each vector once
// Space complexity: O(m+n), stack & hash used n spaces, out used m spaces
// Runtime: 4 ms, faster than 93.90% of C++ online submissions for Next Greater Element I.
// Memory Usage: 9 MB, less than 28.58% of C++ online submissions for Next Greater Element I.

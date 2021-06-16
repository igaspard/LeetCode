class Solution {
   public:
    string reorganizeString(string s) {
        unordered_map<char, int> hash;

        for (auto ch : s) ++hash[ch];

        priority_queue<pair<int, char>> maxHeap;

        for (auto it : hash) maxHeap.push({it.second, it.first});

        string ans;
        while (maxHeap.size() > 1) {
            auto c1 = maxHeap.top();
            maxHeap.pop();
            auto c2 = maxHeap.top();
            maxHeap.pop();

            ans.push_back(c1.second);
            ans.push_back(c2.second);
            if (--c1.first > 0) maxHeap.push(c1);
            if (--c2.first > 0) maxHeap.push(c2);
        }

        if (!maxHeap.empty()) {
            auto c = maxHeap.top();
            if (c.first == 1)
                ans.push_back(c.second);
            else
                return "";
        }

        return ans;
    }
};

// hash + heap
// Runtime: 4 ms, faster than 52.08% of C++ online submissions for Reorganize String.
// Memory Usage: 6.3 MB, less than 56.34% of C++ online submissions for Reorganize String.

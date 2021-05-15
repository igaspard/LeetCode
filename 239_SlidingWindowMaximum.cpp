class MonotonicQueue {
   public:
    void push(int n) {
        while (!data.empty() && n > data.back()) data.pop_back();
        data.push_back(n);
    }

    int max() { return data.front(); }

    void pop(int n) {
        if (!data.empty() && data.front() == n) data.pop_front();
    }

   private:
    deque<int> data;
};

class Solution {
   public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        MonotonicQueue q;
        vector<int> ans;
        for (int i = 0; i < nums.size(); ++i) {
            if (i < k - 1) {
                q.push(nums[i]);
            } else {
                q.push(nums[i]);
                ans.emplace_back(q.max());
                q.pop(nums[i - k + 1]);
            }
        }

        return ans;
    }
};

// Monotonic Queue
// Time complexity: O(N)
// Space complexity: O(K)
// Runtime: 244 ms, faster than 64.08% of C++ online submissions for Sliding Window Maximum.
// Memory Usage: 131.9 MB, less than 50.65% of C++ online submissions for Sliding Window Maximum.

class Solution {
   public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        for (int i = 0; i <= nums.size() - k; ++i) {
            auto it = *max_element(nums.begin() + i, nums.begin() + i + k);
            ans.emplace_back(it);
        }

        return ans;
    }
};

// Time Limit Exceeded
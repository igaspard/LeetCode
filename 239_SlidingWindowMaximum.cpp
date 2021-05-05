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
            if (i < k) {
                q.push(nums[i]);
            } else {
                ans.emplace_back(q.max());
                q.pop(nums[i - k]);
                q.push(nums[i]);
            }
        }
        ans.emplace_back(q.max());
        return ans;
    }
};

// Monotonic Queue 
// Time complexity: O(1)

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
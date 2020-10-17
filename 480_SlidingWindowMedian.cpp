template <typename T, class Container = vector<T>, class Compare = less<typename Container::value_type>>
class priority_queue_with_remove : public priority_queue<T, Container, Compare> {
   public:
    bool remove(const T& valueToRemove) {
        auto itr = std::find(this->c.begin(), this->c.end(), valueToRemove);
        if (itr == this->c.end()) {
            return false;
        }
        this->c.erase(itr);
        // ideally we should not be rebuilding the heap as we are removing only one element
        // a custom implementation of priority queue can adjust only one element in O(logN)
        std::make_heap(this->c.begin(), this->c.end(), this->comp);
        return true;
    }
};

class Solution {
   public:
    priority_queue_with_remove<int> maxHeap;
    priority_queue_with_remove<int, vector<int>, greater<int>> minHeap;

    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> result;
        for (int i = 0; i < nums.size(); ++i) {
            if (maxHeap.empty() || maxHeap.top() >= nums[i])
                maxHeap.emplace(nums[i]);
            else
                minHeap.emplace(nums[i]);
            balanceHeaps();

            if (i >= k - 1) {
                if (maxHeap.size() == minHeap.size())
                    result.emplace_back((maxHeap.top() / 2.0 + minHeap.top() / 2.0));
                else
                    result.emplace_back(maxHeap.top());

                int remove_target = nums[i - k + 1];
                if (remove_target <= maxHeap.top())
                    maxHeap.remove(remove_target);
                else
                    minHeap.remove(remove_target);
                balanceHeaps();
            }
        }
        return result;
    }

    void balanceHeaps() {
        if (maxHeap.size() > minHeap.size() + 1) {
            minHeap.emplace(maxHeap.top());
            maxHeap.pop();
        } else if (maxHeap.size() < minHeap.size()) {
            maxHeap.emplace(minHeap.top());
            minHeap.pop();
        }
    }
};
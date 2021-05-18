class FindSumPairs {
public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        for (auto n : nums1) ++freq1[n];
        for (auto n : nums2) ++freq2[n];

        _nums2 = nums2;
    }
    
    void add(int index, int val) {
        int target = _nums2[index];
        --freq2[target];
        if (freq2[target] == 0) freq2.erase(target);
        ++freq2[target+val];
        _nums2[index] = target + val;
    }
    
    int count(int tot) {
        int ans = 0;
        for (auto entry : freq1) {
            int target = tot - entry.first;
            if (freq2.count(target) != 0) ans += entry.second * freq2[target];
        }

        return ans;
    }
private:
    unordered_map<int, int> freq1;
    unordered_map<int, int> freq2;
    vector<int> _nums2;
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */

class FindSumPairs {
   public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        for (int i = 0; i < nums1.size(); ++i) data1[nums1[i]].emplace_back(i);

        for (int i = 0; i < nums2.size(); ++i) data2[nums2[i]].emplace_back(i);

        _nums2 = nums2;
    }

    void add(int index, int val) {
        int target = _nums2[index];
        if (data2.count(target) != 0) {
            data2[target + val].emplace_back(index);
            auto it = find(data2[target].begin(), data2[target].end(), index);
            if (it != data2[target].end()) data2[target].erase(it);
            if (data2[target].empty()) data2.erase(target);
        }
        _nums2[index] = target + val;
    }

    int count(int tot) {
        int ans = 0;
        for (auto entry : data1) {
            int target = tot - entry.first;
            if (data2.count(target) != 0) ans += entry.second.size() * data2[target].size();
        }

        return ans;
    }

   private:
    unordered_map<int, vector<int>> data1;
    unordered_map<int, vector<int>> data2;
    vector<int> _nums2;
};

// Runtime: 992 ms, faster than 20.00% of C++ online submissions for Finding Pairs With a Certain Sum.
// Memory Usage: 193.9 MB, less than 20.00% of C++ online submissions for Finding Pairs With a Certain Sum.

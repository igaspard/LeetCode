class RandomizedSet {
   public:
    RandomizedSet() {}

    bool insert(int val) {
        if (mapValIdx.count(val)) return false;
        mapValIdx[val] = nums.size();
        nums.emplace_back(val);

        return true;
    }

    bool remove(int val) {
        if (mapValIdx.count(val) == 0) return false;
        int idx = mapValIdx[val];
        // swap the val with last one, and pop_back
        int last = nums.back();
        nums[idx] = last;
        mapValIdx[last] = idx;
        nums.pop_back();
        mapValIdx.erase(val); // erase in the end if there only one element
        return true;
    }

    int getRandom() { return nums[rand() % nums.size()]; }

   private:
    unordered_map<int, int> mapValIdx;
    vector<int> nums;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

// Runtime: 359 ms, faster than 25.22% of C++ online submissions for Insert Delete GetRandom O(1).
// Memory Usage: 97.1 MB, less than 60.57% of C++ online submissions for Insert Delete GetRandom O(1).
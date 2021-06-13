class TimeMap {
   public:
    /** Initialize your data structure here. */
    TimeMap() { hash.clear(); }

    void set(string key, string value, int timestamp) { hash[key].insert({timestamp, value}); }

    string get(string key, int timestamp) {
        if (hash.count(key)) {
            auto it = hash[key].upper_bound(timestamp);
            if (it != hash[key].begin()) {
                return (--it)->second;
            } else {
                return "";
            }
        }

        return "";
    }

   private:
    unordered_map<string, map<int, string>> hash;
};

// hash + binary search + map
// Runtime: 356 ms, faster than 20.59% of C++ online submissions for Time Based Key-Value Store.
// Memory Usage: 130.6 MB, less than 35.78% of C++ online submissions for Time Based Key-Value Store.

class TimeMap {
   public:
    /** Initialize your data structure here. */
    TimeMap() { hash.clear(); }

    void set(string key, string value, int timestamp) { hash[key].push_back({timestamp, value}); }

    string get(string key, int timestamp) {
        if (hash.count(key)) {
            auto &vec = hash[key];

            int left = 0, right = vec.size() - 1;
            string ans = "";
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (vec[mid].first <= timestamp) {
                    ans = vec[mid].second;
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
            return ans;
        }

        return "";
    }

   private:
    unordered_map<string, vector<pair<int, string>>> hash;
};

// hash + binary search
// Runtime: 452 ms, faster than 10.81% of C++ online submissions for Time Based Key-Value Store.
// Memory Usage: 128.5 MB, less than 54.18% of C++ online submissions for Time Based Key-Value Store.

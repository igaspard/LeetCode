
/*
 * @lc app=leetcode id=460 lang=cpp
 *
 * [460] LFU Cache
 */

// @lc code=start
struct Node {
    int key;
    int val;
    int freq;

    Node(int _key, int _val, int _freq): key(_key), val(_val), freq(_freq){}
};

class LFUCache {
    int cap, minfreq;
    unordered_map<int, list<Node>::iterator> key_hash;
    unordered_map<int, list<Node>> freq_hash;
public:
    LFUCache(int capacity) {
        cap = capacity;
        minfreq = 0;
        key_hash.clear();
        freq_hash.clear();
    }
    
    int get(int key) {
        if (!cap) return -1;
        const auto it = key_hash.find(key);
        if (it == key_hash.cend()) return -1;

        auto node = it->second;
        int value = node->val, freq = node->freq;
        freq_hash[freq].erase(node);
        if(freq_hash[freq].size() == 0) {
            freq_hash.erase(freq);
            if(minfreq == freq) ++minfreq;
        }
        freq_hash[freq+1].push_front(Node(key, value, freq+1));
        key_hash[key] = freq_hash[freq+1].begin();
        
        return value;
    }
    
    void put(int key, int value) {
        if (!cap) return;
        const auto it = key_hash.find(key);
        if (it == key_hash.cend()) {
            if (cap == key_hash.size()) {
                auto min = freq_hash[minfreq].back();
                key_hash.erase(min.key);
                freq_hash[minfreq].pop_back();
                if(!freq_hash[minfreq].size()) freq_hash.erase(minfreq);
            }
            freq_hash[1].push_front(Node(key, value, 1));
            key_hash[key] = freq_hash[1].begin();
            minfreq = 1;
        } else {
            auto node = it->second;
            int freq = node->freq;
            freq_hash[freq].erase(node);
            if (!freq_hash[freq].size()) {
                freq_hash.erase(freq);
                if (minfreq == freq) ++minfreq;
            }
            freq_hash[freq+1].emplace_front(Node(key, value, freq+1));
            key_hash[key] = freq_hash[freq+1].begin();
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

// Runtime: 96 ms, faster than 72.61% of C++ online submissions for LFU Cache.
// Memory Usage: 42.3 MB, less than 68.77% of C++ online submissions for LFU Cache.

class LRUCache {
public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        const auto it = hash.find(key);
        
        if (it == hash.cend()) return -1;
        
        cache.splice(cache.begin(), cache, it->second);
        return it->second->second;
    }
    
    void put(int key, int value) {
        const auto it = hash.find(key);
        
        if (it != hash.cend()) {
            cache.splice(cache.begin(), cache, it->second);
            it->second->second = value;
            return;
        }
        
        if (cap == cache.size()) {
            const auto& it = cache.back();
            hash.erase(it.first);
            cache.pop_back();
        }
        
        cache.emplace_front(key, value);
        hash[key] = cache.begin();
    }
private:
    int cap;
    list<pair<int, int>> cache;
    unordered_map<int, list<pair<int, int>>::iterator> hash;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

// Hash + double linked list
// Runtime: 76 ms, faster than 94.58% of C++ online submissions for LRU Cache.
// Memory Usage: 39.9 MB, less than 74.01% of C++ online submissions for LRU Cache.
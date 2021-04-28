class MRUQueue {
public:
    MRUQueue(int n) {
        for (int i = 1; i <= n; ++i)
            data.emplace_back(i);
    }
    
    int fetch(int k) {
        data.emplace_back(data[k-1]);
        data.erase(data.begin()+k-1);
        return data.back();
    }
private:
    vector<int> data;
};

/**
 * Your MRUQueue object will be instantiated and called as such:
 * MRUQueue* obj = new MRUQueue(n);
 * int param_1 = obj->fetch(k);
 */

// Runtime: 96 ms, faster than 75.57% of C++ online submissions for Design Most Recently Used Queue.
// Memory Usage: 34 MB, less than 88.93% of C++ online submissions for Design Most Recently Used Queue.

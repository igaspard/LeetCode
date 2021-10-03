class DetectSquares {
   public:
    int freq[1001][1001] = {};
    DetectSquares() {}

    void add(vector<int> point) {
        int X = point[0];
        int Y = point[1];

        x_hash[X].emplace_back(Y);
        y_hash[Y].emplace_back(X);
        ++freq[X][Y];
    }

    int count(vector<int> point) {
        int X = point[0];
        int Y = point[1];

        if (x_hash.count(X) == 0 || y_hash.count(Y) == 0) return 0;

        int ans = 0;
        for (auto y : x_hash[X]) {
            int h = abs(Y - y);
            if (h == 0) continue;
            for (auto x : y_hash[Y]) {
                int w = abs(X - x);
                if (h == w) ans += freq[x][y];
            }
        }

        return ans;
    }

   private:
    unordered_map<int, vector<int>> x_hash, y_hash;
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */

// hash
// Runtime: 340 ms, faster than 79.78% of C++ online submissions for Detect Squares.
// Memory Usage: 144.3 MB, less than 27.89% of C++ online submissions for Detect Squares.
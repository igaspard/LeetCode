class Solution {
public:
    int minSideJumps(vector<int>& obstacles) {
        const int road_len = obstacles.size();
        vector<vector<int>> roads(3, vector<int>(road_len));

        for (int i = 0; i < road_len; ++i) {
            if (obstacles[i] != 0) {
                int lane = obstacles[i]-1;
                roads[lane][i] = 1;
            }
        }
        
        set<pair<int, int>> visited;
    
        int jumps = 0;
        queue<tuple<int, int, int>> q;
        q.push({1, 0, jumps}); // start from lane 2, point 0
        visited.insert({1, 0});

        while (!q.empty()) {
            int size = q.size();

            for (int i = 0; i < size; ++i) {
                auto pos = q.front();
                q.pop();

                int y = std::get<0>(pos);
                int x = std::get<1>(pos);
                int jump = std::get<2>(pos);
    //            cout << "Cur: " << y << ", " << x << ", " << jump << endl;
                if (x == road_len-1) return jump;

                if (!roads[y][x+1]) { 
                    EnqueuePos(y, x+1, jump, q, visited);
                    continue;
                }
                for (int n = 0; n < 3; ++n) { // add difference lanes w/o obstacles
                    if (y != n && !roads[n][x]) {
                        EnqueuePos(n, x, jump+1, q, visited);
                    }
                }
            }
        }

        return -1;
    }
    
    void EnqueuePos(int y, int x, int j, queue<tuple<int, int, int>> &q, set<pair<int, int>> &visited) {
        auto it = visited.find({y, x});
        if (it == visited.end()) {
            q.push(std::make_tuple(y, x, j));
            visited.insert({y, x});
    }
}

};

// BFS
// Runtime: 1664 ms, faster than 25.00% of C++ online submissions for Minimum Sideway Jumps.
// Memory Usage: 390.8 MB, less than 25.00% of C++ online submissions for Minimum Sideway Jumps.
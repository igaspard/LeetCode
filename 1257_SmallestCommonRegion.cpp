class Solution {
public:
    string findSmallestRegion(vector<vector<string>>& regions, string region1, string region2) {
        unordered_map<string, string> map;
        vector<string> path1, path2;
        
        for (int j = 0; j < regions.size(); ++j)
            for (int i = 1; i < regions[j].size(); ++i)
                map[regions[j][i]] = regions[j][0];
            
        while (!region1.empty()) {
            path1.emplace_back(region1);
            region1 = map[region1];
        }
        
        while (!region2.empty()) {
            path2.emplace_back(region2);
            region2 = map[region2];
        }
        
        for (auto n1 : path1) {
            for (auto n2 : path2) {
                if (n1 == n2)
                    return n1;
            }
        }
        
        return "Not Found";
    }
};

// Runtime: 80 ms, faster than 65.97% of C++ online submissions for Smallest Common Region.
// Memory Usage: 35.3 MB, less than 77.78% of C++ online submissions for Smallest Common Region.
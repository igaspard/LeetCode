class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        vector<int> ans;
        for (int i = 0; i < queries.size(); ++i) {
            int insides = 0;
            for (int j = 0; j < points.size(); ++j) {
                int x = queries[i][0];
                int y = queries[i][1];
                int r = queries[i][2];
                
                int px = points[j][0];
                int py = points[j][1];
                
                if (abs(px-x) * abs(px-x) + abs(py-y) * abs(py-y) <= r*r) ++insides;
            }
            ans.emplace_back(insides);
        }
        
        return ans;
    }
};

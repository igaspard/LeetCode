class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        int i = 0, j = 0;
        vector<vector<int>> ans;
        
        while(i < A.size() && j < B.size()) {
            const int s = max(A[i][0], B[j][0]);
            const int e = min(A[i][1], B[j][1]);
            if (s <= e) {
                vector<int> tmp = {s, e};
                ans.emplace_back(tmp);
            }
                
            
            if(A[i][1] < B[j][1])
                i++;
            else
                j++;    
        }
        
        return ans;
    }
};

Runtime: 68 ms, faster than 74.20% of C++ online submissions for Interval List Intersections.
Memory Usage: 19.3 MB, less than 27.21% of C++ online submissions for Interval List Intersections.
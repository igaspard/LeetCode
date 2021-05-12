class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        map<int, int> m;
    
        for (auto log : logs) {
            m[log[0]]++;
            m[log[1]]--;
        }

        int population = 0, max_popluation = 0, ans = 0;
        for (auto it : m) {
            population += it.second;
            if (population > max_popluation) {
                max_popluation = population;
                ans = it.first;
            }
         }

        return ans;
    }
};

// similar to meeting rooms II, find the max number of overlapping 
// Runtime: 4 ms, faster than 71.43% of C++ online submissions for Maximum Population Year.
// Memory Usage: 8.1 MB, less than 28.57% of C++ online submissions for Maximum Population Year.
class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), [](const vector<int> &A, const vector<int> &B) {
           return A[1] > B[1]; 
        });
        int taken = 0;
        int ans = 0;
        for (auto box : boxTypes) {
            if (taken + box[0] <= truckSize) {
                taken += box[0];
                ans += box[0] * box[1];
            } else {
                int remain = truckSize - taken;
                taken += remain;
                ans += remain * box[1];
            }
            
            if (taken == truckSize) return ans;
        }
        
        return ans;
    }
};

// sort
// Runtime: 64 ms, faster than 34.43% of C++ online submissions for Maximum Units on a Truck.
// Memory Usage: 17 MB, less than 38.93% of C++ online submissions for Maximum Units on a Truck.

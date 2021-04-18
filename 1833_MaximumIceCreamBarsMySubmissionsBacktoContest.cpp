class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        long sum = 0;
        int ans = 0;
        std::sort(costs.begin(), costs.end());

        for (auto it : costs) {
            sum += it;
            if (sum <= coins) ans++;
        }

        return ans;
    }
};

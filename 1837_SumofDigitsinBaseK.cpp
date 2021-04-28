class Solution {
public:
    int sumBase(int n, int k) {
        int ans = 0;
        int tmp = n;

        while(tmp > 0) {
            int remainder = tmp % k;
            tmp /= k;
            ans += remainder;
        }

        return ans;
    }
};
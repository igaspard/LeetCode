#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        for (int i = left; i <= right; i++) {
            int s = i, n;
            bool bSelfDivided = true;
            while (s > 0) {
                n = s % 10;
                if (!n || (i % n)) {
                    bSelfDivided = false;
                    break;
                }
                s /= 10;
            }
            if (bSelfDivided)
                ans.push_back(i);
        }
        return ans;
    }
};

int main(int argc, char const *argv[]) {
    Solution mysolution;
    vector<int> out = mysolution.selfDividingNumbers(1, 22);

    for (size_t i = 0; i < out.size(); i++)
        cout<<out[i]<<" ";
    cout<<endl;

    return 0;
}

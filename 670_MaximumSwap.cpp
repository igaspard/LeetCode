#include <iostream>
using namespace std;

class OnePassSolution {
public:
    int maximumSwap(int num) {
        string numstr = to_string(num);

        int maxidx = -1; int maxdigit = -1;
        int leftidx = -1; int rightidx = -1;

        for (int i = numstr.size() - 1; i >= 0; --i) {
            // current digit is the largest by far
            if (numstr[i] > maxdigit) {
                maxdigit = numstr[i];
                maxidx = i;
                continue;
            }

            // best candidate for max swap if there is no more
            // such situation on the left side
            if (numstr[i] < maxdigit) {
                leftidx = i;
                rightidx = maxidx;
            }
        }

        // num is already in order
        if (leftidx == -1) return num;

        swap(numstr[leftidx], numstr[rightidx]);

        return stoi(numstr);
    }
};


int main(int argc, char const *argv[]) {
    OnePassSolution mysolution;
    cout<<mysolution.maximumSwap(123456789)<<endl;
    cout<<mysolution.maximumSwap(2736)<<endl;
    cout<<mysolution.maximumSwap(9973)<<endl;
    cout<<mysolution.maximumSwap(12)<<endl;

    cout<<mysolution.maximumSwap(98368)<<endl;

    return 0;
}

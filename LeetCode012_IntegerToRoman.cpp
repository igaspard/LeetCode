#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        int range[7]    = {1000, 500, 100, 50, 10, 5, 1};
        int syntax[7]   = {'M', 'D', 'C', 'L', 'X', 'V', 'I'};
        int tmp = num;
        string out;

        // over 1000, M
        if (tmp >= range[0]) {
            int count = tmp / range[0];
            for (size_t i = 0; i < count; i++)
                out.push_back(syntax[0]);
            tmp = tmp % range[0];
        }
        // 900, subtractive notation. CM
        if (tmp >= range[0]-range[2]) {
            out.push_back(syntax[2]);
            out.push_back(syntax[0]);
            tmp = tmp % (range[0]-range[2]);
        }
        // 500, D
        if (tmp >= range[1]) {
            out.push_back(syntax[1]);
            tmp = tmp % range[1];
        }
        // 400, subtractive notation, CD
        if (tmp >= range[1]-range[2]) {
            out.push_back(syntax[2]);
            out.push_back(syntax[1]);
            tmp = tmp % (range[1]-range[2]);
        }
        //100, C
        if (tmp >= range[2]) {
            int count = tmp / range[2];
            for (size_t i = 0; i < count; i++)
                out.push_back(syntax[2]);
            tmp = tmp % range[2];
        }
        // 90, subtractive notation. XC
        if (tmp >= range[2]-range[4]) {
            out.push_back(syntax[4]);
            out.push_back(syntax[2]);
            tmp = tmp % (range[2]-range[4]);
        }
        // 50, L
        if (tmp >= range[3]) {
            out.push_back(syntax[3]);
            tmp = tmp % range[3];
        }
        // 40, subtractive notation. XL
        if (tmp >= range[3]-range[4]) {
            out.push_back(syntax[4]);
            out.push_back(syntax[3]);
            tmp = tmp % (range[3]-range[4]);
        }
        // 10, X
        if (tmp >= range[4]) {
            int count = tmp / range[4];
            for (size_t i = 0; i < count; i++)
                out.push_back(syntax[4]);
            tmp = tmp % range[4];
        }
        // 9, subtractive notation. IX
        if (tmp >= range[4]-range[6]) {
            out.push_back(syntax[6]);
            out.push_back(syntax[4]);
            tmp = tmp % (range[4]-range[6]);
        }
        // 5. V
        if (tmp >= range[5]) {
            out.push_back(syntax[5]);
            tmp = tmp % range[5];
        }
        // 4, subtractive notation, IV
        if (tmp >= range[5]-range[6]) {
            out.push_back(syntax[6]);
            out.push_back(syntax[5]);
            tmp = tmp % (range[5]-range[6]);
        }
        // 1, I
        if (tmp >= range[6]) {
            int count = tmp / range[6];
            for (size_t i = 0; i < count; i++) {
                out.push_back(syntax[6]);
            }
        }
        return out;
    }
};

int main(int argc, char const *argv[]) {
  Solution mysolution;
  for (size_t i = 1; i < 4000; i++) {
      cout<<"Ronam Numeral "<<i<<": "<<mysolution.intToRoman(i)<<endl;
  }
  return 0;
}

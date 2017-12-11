class Solution {
public:
    string convertToBase7(int num) {
        string base7;
        int sign;
        if (num < 0) {
            sign = -1;
            base7.push_back('-');
        }
        else
            sign = 1;

        int tmp = num*sign;
        int max = 1;
        while (tmp >= pow(7, max))
            max++;
        cout<< max<<endl;

        for (int i = max-1; i >= 0; i--) {
            int d = tmp / pow(7, i);
            base7.push_back((char)'0'+d);
            tmp -= d * pow(7, i);
        }

        return base7;
    }
};

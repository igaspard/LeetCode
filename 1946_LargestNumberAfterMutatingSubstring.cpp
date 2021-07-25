class Solution {
public:
    string maximumNumber(string num, vector<int>& change) {
        bool mutated = false;
        for (auto &ch : num) {
            int val = ch - '0';
            char replaced = '0' + change[val];
            if (mutated) {
                if (change[val] >= val) ch = replaced;
                else break;
            } else if (change[val] > val) {
                ch = replaced;
                mutated = true;
            }
        }
        
        return num;
    }
};

// greedy
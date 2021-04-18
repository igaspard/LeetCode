class Solution {
public:
    bool checkIfPangram(string sentence) {
        if (sentence.length() < 26) return false;
        unordered_set<char> set;
        
        for (auto ch : sentence) {
            set.insert(ch);
            if (set.size()==26) {
                return true;
            }
        }
        
        return false;
    }
};

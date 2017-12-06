class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==1)
            return strs[0];
        if(strs.size()==0)
            return "";
        string out;
        bool same = true;
        for(int i = 0; i < strs[0].size(); i++) {
            for(int j = 0; j < strs.size(); j++) {
                if(strs[0][i]!=strs[j][i]) {
                    same = false;
                    break;
                }
            }
            if(same)
                out.push_back(strs[0][i]);
            else
                break;
        }
        return out;
    }
};

class Solution {
public:
    vector<int> anagramMappings(vector<int>& A, vector<int>& B) {
        vector<int> P;

        for(int i = 0; i < A.size(); i++) {
            for(int j = 0; j < B.size(); j++) {
                if(A[i] == B[j]) {
                    P.push_back(j);
                    break;
                }
            }
        }
        return P;
    }
};

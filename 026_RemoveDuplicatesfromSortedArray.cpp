class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 1)
            return nums.size();
        
        int i = 1, u = 0;
        do{
            if (nums[u] == nums[u+1]) {
                u++;
            }
            else {
                nums[i] = nums[u+1];
                u++; i++;
            }
            
        }while(u < nums.size()-1);
        
        return i;
    }
};
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> answers;
        
        if (nums.size() < 3)
            return answers;
        
        std::sort(nums.begin(), nums.end());
        
        for (int i=0; i < nums.size()-2; i++) {
            int target = -nums[i];
            int f = i + 1;
            int b = nums.size() - 1;
            
            while (f < b) {
                int sum = nums[f] + nums[b];
                
                if (sum < target)
                    f++;
                else if (sum > target)
                    b--;
                else {
                    vector<int> answer{nums[i], nums[f], nums[b]};
                    answers.push_back(answer);
                    
                    while (f < b && nums[f]==answer[1]) f++;
                    while (f < b && nums[b]==answer[2]) b--;
                }
            }
            while (i+1 < nums.size() && nums[i+1]==nums[i]) i++;
        }
        return answers;
    }
};
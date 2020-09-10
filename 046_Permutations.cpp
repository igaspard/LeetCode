class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        queue<vector<int>> tmp;
        tmp.push(vector<int>());
        
        for (auto num: nums) {
            const int N = tmp.size();
            
            for (int i = 0; i < N; ++i) {
                vector<int> item = tmp.front();
                tmp.pop();
                
                for (int j = 0; j <= item.size(); ++j) {
                    vector<int> new_item(item);
                    new_item.insert(new_item.begin()+j, num);
                    if (new_item.size() == nums.size()) 
                        ans.emplace_back(new_item);
                    else
                        tmp.push(new_item);
                }
            }
        }
            
        return ans;
    }
};

// Runtime: 8 ms, faster than 39.00% of C++ online submissions for Permutations.
// Memory Usage: 8.1 MB, less than 29.59% of C++ online submissions for Permutations.

class Solution {
public:
    vector<int> insertIntAt(vector<int> input, int c, int idx) {
        vector<int> output;
        for (int i = 0, j = 0; j < input.size()+1; j++) {
            if ( j != idx )
                output.emplace_back(input[i++]);
            else
                output.emplace_back(c);
        }
        return output;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector< vector<int> > ans;
        if (nums.size() == 1) {
            ans.emplace_back(nums);
            return ans;
        }

        int first = nums[0];
        vector<int> rem (nums.begin()+1, nums.end());
        vector< vector<int> > next = permute(rem);
        for (size_t i = 0; i < next.size(); i++) {
            for (size_t j = 0; j < next[i].size()+1; j++) {
                ans.emplace_back(insertIntAt(next[i], first, j));
            }
        }
        return ans;
    }
};

// Runtime: 16 ms, faster than 18.62% of C++ online submissions for Permutations.
// Memory Usage: 9.9 MB, less than 22.39% of C++ online submissions for Permutations.
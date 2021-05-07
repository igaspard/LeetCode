class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        stack<int> s;
        
        vector<int>ans(T.size());
        for(int i = T.size()-1; i >= 0; --i) {
            while(!s.empty() && T[i] >= T[s.top()]) {
                s.pop();
            }
            ans[i] = s.empty() ? 0 : s.top() - i;
            
            s.push(i);
        }
        
        return ans;
    }
};

// Monotonic Stack, only use idx in the stack
// Runtime: 48 ms, faster than 94.87% of C++ online submissions for Daily Temperatures.
// Memory Usage: 40 MB, less than 68.00% of C++ online submissions for Daily Temperatures.

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        stack<pair<int, int>> s;
        
        vector<int>ans(T.size());
        for(int i = T.size()-1; i >= 0; --i) {
            while(!s.empty() && T[i] >= s.top().first) {
                s.pop();
            }
            ans[i] = s.empty() ? 0 : s.top().second - i;
            
            s.push(make_pair(T[i], i));
        }
        
        return ans;
    }
};

// Monotonic Stack, use pair of temperatures and idx in stack
// Runtime: 68 ms, faster than 23.58% of C++ online submissions for Daily Temperatures.
// Memory Usage: 40 MB, less than 68.00% of C++ online submissions for Daily Temperatures.
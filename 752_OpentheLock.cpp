class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> dead(deadends.begin(), deadends.end());
        if (dead.count(start)) return -1;
        if (target==start) return 0;
        
        unordered_set<string> visited;
        unordered_set<string> q1;
        unordered_set<string> q2;
        q1.insert("0000");
        q2.insert(target);
        
        int ans = 0;
        while(!q1.empty() && !q2.empty()) {
            unordered_set<string> temp;
            
            for (auto cur : q1) {
                if (dead.count(cur)) continue;
                if (q2.count(cur)) return ans;
                
                visited.insert(cur);
                for (int j = 0; j < 4; ++j) {
                    string up = plusOne(cur, j);
                    if (!visited.count(up)) temp.insert(up);
                    
                    string down = minusOne(cur, j);
                    if (!visited.count(down)) temp.insert(down);
                }   
            }
            ++ans;
            q1 = q2;
            q2 = temp;
        }
        
        return -1;
    }
    
    static string plusOne(string s, int j) {
        if (s[j] == '9') s[j] = '0';
        else ++s[j];
        
        return string(s);
    }
    
    static string minusOne(string s, int j) {
        if (s[j] == '0') s[j] = '9';
        else --s[j];
        
        return string(s);
    }
};

// Bidirectional BFS
// Runtime: 60 ms, faster than 94.13% of C++ online submissions for Open the Lock.
// Memory Usage: 19.1 MB, less than 93.96% of C++ online submissions for Open the Lock.

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        const string start = "0000";
        unordered_set<string> deads(deadends.begin(), deadends.end());
        
        if (deads.count(start)) return -1;
        if (target==start) return 0;
        
        unordered_set<string> visited{start};
        
        queue<string> q;
        q.push(start);
        
        int ans = 0;
        while(!q.empty()) {
            int level_size = q.size();
            
            for (int i = 0; i < level_size; ++i) {
                const string cur = q.front();
                q.pop();
                
                if (deads.count(cur))
                    continue;
                if (cur == target)
                    return ans;
                
                for (int j = 0; j < 4; ++j) {
                    string up = plusOne(cur, j);
                    if (!visited.count(up)) {
                        q.push(up);
                        visited.insert(up);
                    }
                    
                    string down = minusOne(cur, j);
                    if (!visited.count(down)) {
                        q.push(down);
                        visited.insert(down);
                    }
                }
            }
            ++ans;
        }
        
        return -1;
    }
    
    static string plusOne(string s, int j) {
        if (s[j] == '9') s[j] = '0';
        else ++s[j];
        
        return string(s);
    }
    
    static string minusOne(string s, int j) {
        if (s[j] == '0') s[j] = '9';
        else --s[j];
        
        return string(s);
    }
};

// BFS
// Runtime: 200 ms, faster than 53.68% of C++ online submissions for Open the Lock.
// Memory Usage: 35.7 MB, less than 51.12% of C++ online submissions for Open the Lock.
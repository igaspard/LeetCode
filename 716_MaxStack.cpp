class MaxStack {
public:
    /** initialize your data structure here. */
    MaxStack() {
        
    }
    
    void push(int x) {
        s.push(x);
        
        if (max_s.empty() || x >= max_s.top()) max_s.push(x);
    }
    
    int pop() {
        if (max_s.top() == s.top()) max_s.pop();
        
        int ans = s.top();
        s.pop();
        
        return ans;
    }
    
    int top() {
        return s.top();
    }
    
    int peekMax() {
        return max_s.top();
    }
    
    int popMax() {
        int ans = max_s.top();
        max_s.pop();
        
        stack<int> t;
        while (s.top() != ans) {
            t.push(s.top());
            s.pop();
        }
        
        s.pop();
        while (!t.empty()) {
            push(t.top()); // 
            t.pop();
        }
        return ans;
    }
private:
    stack<int> s, max_s;
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack* obj = new MaxStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->peekMax();
 * int param_5 = obj->popMax();
 */

// Two Stacks, another one for recording max
// Runtime: 60 ms, faster than 93.08% of C++ online submissions for Max Stack.
// Memory Usage: 41.1 MB, less than 41.85% of C++ online submissions for Max Stack.

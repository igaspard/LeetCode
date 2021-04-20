/*
 * @lc app=leetcode id=155 lang=cpp
 *
 * [155] Min Stack
 */

// @lc code=start
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int val) {
        s.push(val);

        if (min_s.empty() || val <= min_s.top()) min_s.push(val); 
    }
    
    void pop() {
        if (s.top() == min_s.top()) min_s.pop();
        s.pop();  
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return min_s.top();
    }
private:
    stack<int> s, min_s;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end


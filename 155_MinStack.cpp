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

// push, pop, getMin O(N)
// Runtime: 27 ms, faster than 45.07% of C++ online submissions for Min Stack.
// Memory Usage: 16.3 MB, less than 68.88% of C++ online submissions for Min Stack.


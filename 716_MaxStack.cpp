/*
Problem

Design a max stack that supports push, pop, top, peekMax and popMax.

push(x) -- Push element x onto stack.
pop() -- Remove the element on top of the stack and return it.
top() -- Get the element on the top.
peekMax() -- Retrieve the maximum element in the stack.
popMax() -- Retrieve the maximum element in the stack, and remove it. 
If you find more than one maximum elements, only remove the top-most one.

Example 1:

MaxStack stack = new MaxStack();
stack.push(5); 
stack.push(1);
stack.push(5);
stack.top(); -> 5
stack.popMax(); -> 5
stack.top(); -> 1
stack.peekMax(); -> 5
stack.pop(); -> 1
stack.top(); -> 5

Note: 
-1e7 <= x <= 1e7 
Number of operations won't exceed 10000. 
The last four operations won't be called when stack is empty.
*/
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
        // find the max in the original stack, save into temp stack
        stack<int> t;
        while (s.top() != ans) {
            t.push(s.top());
            s.pop();
        }
        // find the max one, pop it out, restore the temp back to stack
        s.pop();
        while (!t.empty()) {
            push(t.top());
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

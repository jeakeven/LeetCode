/*

Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

    push(x) -- Push element x onto stack.
    pop() -- Removes the element on top of the stack.
    top() -- Get the top element.
    getMin() -- Retrieve the minimum element in the stack.

*/

class MinStack {
private:
    stack<int> stk;
    stack<int> minStk;

public:
    void push(int x) {
        stk.push(x);
        if(!minStk.size() || minStk.top() >= x) {
            minStk.push(x);
        }
    }

    void pop() {
        if(!stk.empty()) {
            if(!minStk.empty() && stk.top() == minStk.top()) {
                minStk.pop();
            }
            stk.pop();
        }
    }

    int top() {
        if(!stk.empty()) {
            return stk.top();
        }
    }

    int getMin() {
        if(!minStk.empty()) {
            return minStk.top();
        }      
    }
};
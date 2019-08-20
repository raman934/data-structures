/* Design a stack that supports push, pop, top, and retrieving the minimum
   element in constant time.

    push(x) -- Push element x onto stack.
    pop() -- Removes the element on top of the stack.
    top() -- Get the top element.
    getMin() -- Retrieve the minimum element in the stack.


    Example:

    MinStack minStack = new MinStack();
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    minStack.getMin();   --> Returns -3.
    minStack.pop();
    minStack.top();      --> Returns 0.
    minStack.getMin();   --> Returns -2.

   LC 155. Min Stack
   Author: Shruti
*/

class MinStack {
    stack<int> stk;
    stack<int> min_stk; // to track curr known min elem
    int min_val = INT_MAX;
public:
    /** initialize your data structure here. */
    MinStack() {

    }

    void push(int x) {
        stk.push(x);
        if(min_stk.empty()) { // push curr min in min_stk
            min_stk.push(x);
        } else {
            min_stk.push(min(min_stk.top(), x));
        }
    }

    void pop() {
        stk.pop();
        min_stk.pop();
    }

    int top() {
        return stk.top();
    }

    int getMin() {
        return min_stk.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

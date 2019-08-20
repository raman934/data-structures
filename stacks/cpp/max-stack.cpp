/* Design a max stack that supports push, pop, top, peekMax and popMax.

    push(x) -- Push element x onto stack.
    pop() -- Remove the element on top of the stack and return it.
    top() -- Get the element on the top.
    peekMax() -- Retrieve the maximum element in the stack.
    popMax() -- Retrieve the maximum element in the stack, and remove it. If
    you find more than one maximum elements, only remove the top-most one.

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

   LC 716. Max Stack
   Author: Shruti
*/

class MaxStack {
    stack<int> stk;
    stack<int> max_stk; // to track max elements, keeps curr max seen till curr index
    // only peekMax and popMax require max_stk
public:
    /** initialize your data structure here. */
    MaxStack() {}

    void push(int x) {
        stk.push(x);
        // push current max seen for each insertion in the other stk
        if(max_stk.empty()) {
            max_stk.push(x);
        } else {
            max_stk.push(max(x, max_stk.top()));
        }
    }

    int pop() {
        int temp = stk.top();
        stk.pop();
        max_stk.pop(); // remove corresponding max val seen at the popped value
        return temp;
    }

    int top() {
        return stk.top();
    }

    int peekMax() {
        return max_stk.top();
    }

    int popMax() {
        int max_val = peekMax();
        stack<int> buffer;
        while(stk.top() != max_val) { // remove top elements and store in buffer till max_val not found
            buffer.push(pop());
        }
        pop(); // remove max_val
        while(!buffer.empty()) {
            push(buffer.top()); // put all the elements back
            buffer.pop();
        }
        return max_val;
    }
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

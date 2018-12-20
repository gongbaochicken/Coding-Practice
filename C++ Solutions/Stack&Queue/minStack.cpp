//Min Stack
/*
 Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

    push(x) -- Push element x onto stack.
    pop() -- Removes the element on top of the stack.
    top() -- Get the top element.
    getMin() -- Retrieve the minimum element in the stack.

*/

class MinStack {
public:
    stack<int> data;
    stack<int> min;

    /** initialize your data structure here. */
    MinStack() {

    }
    
    void push(int x) {
        data.push(x);
        if(min.empty() || min.top() >= x){
            min.push(x);
        }
    }

    void pop() {
        if(!min.empty() && min.top() == data.top()){
            min.pop();
        }
        data.pop();
    }

    int top() {
        return data.top();
    }

    int getMin() {
        return min.top();
    }
};

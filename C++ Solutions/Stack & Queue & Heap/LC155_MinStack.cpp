// 155 Min Stack
/*
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

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
*/

class MinStack {
public:
    stack<int> data;
    stack<int> min;

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
// Implement Stack using Queues

// Implement the following operations of a stack using queues.

//     push(x) -- Push element x onto stack.
//     pop() -- Removes the element on top of the stack.
//     top() -- Get the top element.
//     empty() -- Return whether the stack is empty.

class MyStack {
public:
    queue<int> que;

    /** Initialize your data structure here. */
    MyStack() {

    }

    /** Push element x onto stack. */
    void push(int x) {
        que.push(x);
        while(que.front() != x){
          que.push(que.front());
          que.pop();
        }
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int val = que.front();
        que.pop();
        return val;
    }

    /** Get the top element. */
    int top() {
        return que.front();
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return que.empty();
    }
};

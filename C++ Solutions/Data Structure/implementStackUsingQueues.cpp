// Implement Stack using Queues 

// Implement the following operations of a stack using queues.

//     push(x) -- Push element x onto stack.
//     pop() -- Removes the element on top of the stack.
//     top() -- Get the top element.
//     empty() -- Return whether the stack is empty.

// Notes:

//     You must use only standard operations of a queue -- which means only push to back, peek/pop from 
//front, size, and is empty operations are valid. Depending on your language, queue may not be supported natively. 
//You may simulate a queue by using a list or deque (double-ended queue), as long as you use only standard operations 
//of a queue. You may assume that all operations are valid (for example, no pop or top operations will be called on an 
//empty stack).

// Update (2015-06-11):
// The class name of the Java function had been updated to MyStack instead of Stack.

class Stack {
public:
    queue<int> Q; 
    // Push element x onto stack.
    void push(int x) {
        Q.push(x);
        for(int i = 0; i < Q.size()-1; i++){
            Q.push(Q.front());
            Q.pop();
        }
    }

    // Removes the element on top of the stack.
    void pop() {
        Q.pop();
    }

    // Get the top element.
    int top() {
        return Q.front();
    }

    // Return whether the stack is empty.
    bool empty() {
        return Q.size() == 0;
    }
};
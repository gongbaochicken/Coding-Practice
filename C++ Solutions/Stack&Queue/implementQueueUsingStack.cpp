// Implement the following operations of a queue using stacks.

// push(x) -- Push element x to the back of queue.
// pop() -- Removes the element from in front of queue.
// peek() -- Get the front element.
// empty() -- Return whether the queue is empty.

// You must use only standard operations of a stack -- which means only push to top, peek/pop from top,
// size, and is empty operations are valid.

// Depending on your language, stack may not be supported natively. You may simulate a stack by using a list
// or deque (double-ended queue), as long as you use only standard operations of a stack. You may assume that
// all operations are valid (for example, no pop or peek operations will be called on an empty queue).


class MyQueue {
public:
    /** Initialize your data structure here. */
    stack<int> in;
    stack<int> out;

    MyQueue() {

    }

    /** Push element x to the back of queue. */
    void push(int x) {
        in.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if(out.empty()){
          transfer();
        }
        int x = out.top();
        out.pop();
        return x;
    }

    /** Get the front element. */
    int peek() {
      if(out.empty()){
        transfer();
      }
      return out.top();
    }

    void transfer(){
      while(!in.empty()){
        int top = in.top();
        in.pop();
        out.push(top);
      }
    }

    /** Returns whether the queue is empty. */
    bool empty() {
      if(out.empty() && in.empty()){
        return true;
      }else{
        return false;
      }
    }
};

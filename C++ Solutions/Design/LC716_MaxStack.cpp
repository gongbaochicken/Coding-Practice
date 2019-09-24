// 716. Max Stack
/*
Design a max stack that supports push, pop, top, peekMax and popMax.

push(x) -- Push element x onto stack.
pop() -- Remove the element on top of the stack and return it.
top() -- Get the element on the top.
peekMax() -- Retrieve the maximum element in the stack.
popMax() -- Retrieve the maximum element in the stack, and remove it. If you find more than one maximum elements, only remove the top-most one.
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
        data.insert(data.begin(), x);
        mp[x].push_back(data.begin());
    }
    
    int pop() {
        int x = *data.begin();
        mp[x].pop_back();
        if (mp[x].empty()) mp.erase(x);
        data.erase(data.begin());
        return x;
    }
    
    int top() {
        return *data.begin();
    }
    
    int peekMax() {
        return mp.rbegin()->first;
    }

    int popMax() {
        int x = mp.rbegin()->first;
        list<int>::iterator iter = mp[x].back();
        mp[x].pop_back();
        if (mp[x].empty()) mp.erase(x);
        data.erase(iter);
        return x;
    }

private:
    list<int> data;
    map<int, vector<list<int>::iterator>> mp;
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack obj = new MaxStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.peekMax();
 * int param_5 = obj.popMax();
 */
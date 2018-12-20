// Solution: Using linked list for dynamic grow and shrink:

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int value): val(value), next(nullptr) {}
};

class MyStack{
public:
    MyStack(): len(0){};
    ~MyStack() {
        //
    }
    
    void push(int value) {
        ListNode* newNode = new ListNode(value);
        newNode->next = head;
        head = newNode;
        ++len;
    }
    
    int top(){
        if (head != nullptr) {
            return head->val;
        }
        return -1;
    }
    
    void pop(){
        if (len == 0) return;
        ListNode* temp = head;
        head = head->next;
        delete temp;
        --len;
    }
    
    bool empty(){
        return len == 0;
    }
    
    int size(){
        return len;
    }
    
private:
    ListNode* head;
    int len;
};


int main()
{
    vector<int> v = {3,2,1,4,5};
    MyStack st;
    for (auto x: v) {
        st.push(x);
    }
    
    while(!st.empty()) {
        int topV = st.top();
        st.pop();
        std::cout << topV <<" ";
    }
    std::cout << endl;
    // 5 4 1 2 3
}

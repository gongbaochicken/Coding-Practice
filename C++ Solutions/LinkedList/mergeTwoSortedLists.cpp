// Merge Two Sorted Lists

// Merge two sorted linked lists and return it as a new list. The new list should
//  be made by splicing together the nodes of the first two lists.


//Solution: Using a dummy node

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        ListNode * dummy = new ListNode(-1);
        ListNode * curr = dummy;
        while(l1 != NULL && l2 != NULL){
            if(l1->val < l2->val){
                curr->next = l1;
                l1 = l1->next;
            }else{
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }
        if(l1 == NULL) curr->next = l2;
        if(l2 == NULL) curr->next = l1;
        ListNode * key = dummy->next;
        delete dummy; 
        return key;
    }
};

// Cost Analysis:
// Time: O(n)， OJ Test Time: 12ms, Space: O(1)


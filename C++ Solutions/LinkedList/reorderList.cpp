//Reorder List
//Question:
// Given a singly linked list L: L0→L1→…→Ln-1→Ln,
// reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

// You must do this in-place without altering the nodes' values.

// For example,
// Given {1,2,3,4}, reorder it to {1,4,2,3}. 

//C++ Code:

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {
        if(head == NULL || head->next == NULL) return;
        ListNode *slow = head, *fast = head;
        //Find the middle node
        while(fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode *mid = slow->next;
        //Using two pointers
        ListNode *last = mid;
        ListNode *prev = NULL;
        //Reorder the second part
        while(last != NULL){
           ListNode *next = last->next;
           last->next = prev;
           prev = last;
           last = next;
        }
        //Define the tail of the linkedlist
        slow->next = NULL;
        while(head && prev){
            ListNode *next1=head->next;
            head->next=prev;
            prev=prev->next;
            head->next->next=next1;
            head=next1;
        }
    }
};
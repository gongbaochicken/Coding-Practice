//Remove Nth Node From End of List 
/*
Given a linked list, remove the nth node from the end of list and return its head.

For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5.

Note:
Given n will always be valid.
Try to do this in one pass. 
*/

//Solution in C++:
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *slow = head;
        ListNode *fast = head;
        for (int i = 0; i < n; i++) {
            fast = fast->next;
         }
        if (fast == NULL) {
            return slow->next;
         }
        while (fast->next != NULL) {
            slow = slow->next;
            fast = fast->next;
         }
         slow->next = slow->next->next;
         return head;
    }
};
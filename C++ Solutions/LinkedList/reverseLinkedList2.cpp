// Reverse Linked List II

// Reverse a linked list from position m to n. Do it in-place and in one-pass.

// For example: Given 1->2->3->4->5->NULL, m = 2 and n = 4,

// return 1->4->3->2->5->NULL.

// Note:
// Given m, n satisfy the following condition:
// 1 ≤ m ≤ n ≤ length of list. 

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* pre = dummy;
        /* Locate pre. */
        for (int i = 0; i < m - 1; i++) 
            pre = pre -> next;
        /* Reverse nodes after cur. */
        ListNode* cur = pre->next;
        for (int i = 0; i < n - m; i++) {
            ListNode* move = cur->next;
            cur->next = move->next;
            move->next = pre->next;
            pre->next = move;
        }
        ListNode* key = dummy->next;
        delete dummy;
        return key;
    }
};
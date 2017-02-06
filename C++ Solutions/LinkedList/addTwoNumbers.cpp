//Add Two Numbers
/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
 */

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;
        ListNode* h1 = l1, *h2 = l2;
        int carry = 0;
        while(h1 != nullptr || h2 != nullptr){
            int v1 = h1 == nullptr? 0: h1->val;
            int v2 = h2 == nullptr? 0: h2->val;
            int val = (v1 + v2 + carry) % 10;
            carry = (v1 + v2 + carry)/10;
            curr->next = new ListNode(val);
            curr = curr->next;
            h1 = h1==nullptr? nullptr:h1->next;
            h2 = h2==nullptr? nullptr:h2->next;
        }
        if(carry > 0){
            curr->next = new ListNode(carry);
        }
        return dummy->next;
    }
};

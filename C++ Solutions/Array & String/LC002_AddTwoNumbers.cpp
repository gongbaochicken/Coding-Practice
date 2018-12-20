// 2. Add Two Numbers
// DescriptionHintsSubmissionsDiscussSolution
// You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
//
// You may assume the two numbers do not contain any leading zero, except the number 0 itself.
//
// Example
// Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)， Output: 7 -> 0 -> 8
// Explanation: 342 + 465 = 807.

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
        while(h1 != nullptr || h2 != nullptr) {
            int val1 = h1 == nullptr? 0 : h1->val;
            int val2 = h2 == nullptr? 0 : h2->val;
            int value = (val1 + val2 + carry)%10;
            carry = (val1 + val2 + carry)/10;
            curr->next = new ListNode(value);
            curr = curr->next;
            h1 = h1 == nullptr? nullptr : h1->next;
            h2 = h2 == nullptr? nullptr : h2->next;
        }
        if (carry > 0) {
            curr->next = new ListNode(carry);
        }
        return dummy->next;
    }
};

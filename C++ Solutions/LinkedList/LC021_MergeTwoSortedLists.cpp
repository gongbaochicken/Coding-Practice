/*
Merge two sorted linked lists and return it as a new list. 
The new list should be made by splicing together the nodes of the first two lists.

Example:
Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr) return l2;
        if(l2 == nullptr) return l1;
        ListNode* dummy = new ListNode(-1);
        ListNode* p = dummy;
        while(l1 != nullptr && l2 != nullptr){
            if(l1->val > l2->val){
                p->next = new ListNode(l2->val);
                l2 = l2->next;
            }else{
                p->next = new ListNode(l1->val);
                l1 = l1->next;
            }
            // note: very import detail!
            p = p->next;
        }
        if(l1 == nullptr) p->next = l2;
        if(l2 == nullptr) p->next = l1;
        return dummy->next;
    }
};
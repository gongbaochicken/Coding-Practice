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
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode *slow = head, *fast = head;
        while(fast->next && fast->next->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode *l2 =slow->next;
        slow->next = NULL;
        return merge(sortList(head), sortList(l2));
    }
    
    ListNode* merge(ListNode* l1, ListNode* l2) {
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        ListNode * dummy = new ListNode(-1);
        ListNode * p = dummy;
        while(l1 != NULL && l2 != NULL){
            if(l1->val < l2->val){
                p->next = l1;
                l1 = l1->next;
            }else{
                p->next = l2;
                l2 = l2->next;
            }
            p = p->next;
        }
        if(l1 == NULL) p->next = l2;
        if(l2 == NULL) p->next = l1;
        return dummy->next;
     }
};
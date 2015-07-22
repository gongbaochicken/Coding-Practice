/**Title: Palindrome Linked List 

Question:
Given a singly linked list, determine if it is a palindrome.

Follow up:
Could you do it in O(n) time and O(1) space?
**/

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
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL) return true;
        
        ListNode *fast = head->next, *slow = head;
        while(fast != NULL && fast->next != NULL ){
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode *laterList = reverseList(slow->next);
        slow->next = NULL;
        while(laterList && head){
            if(laterList->val != head->val){
                return false;
            }else{
                laterList = laterList->next;
                head = head->next;
            }
        }
        return true;
    }
    
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        while(head != NULL && head->next != NULL){
            ListNode* next = head->next->next;
            head->next->next = dummy->next;
            dummy->next = head->next;
            head->next = next;
        }
        ListNode* key = dummy->next;
        delete dummy;
        return key;
    }
};
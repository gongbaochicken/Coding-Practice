//Remove Duplicates from Sorted List

/*
 Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3. 
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 //Solution 1: Dummy node
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* next = head;
        ListNode* curr = dummy;
        while(next != nullptr && next->next != nullptr) {
            if(next->val == next->next->val){
                ListNode* temp = next;
                curr->next = curr->next->next;
                next = next->next;
                temp = nullptr;
                delete(temp);
            }else{
                curr = curr->next;
                next = next->next;
            }
        }
        return dummy->next;
    }
};


//Solution 2: Concise
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        //if(head == nullptr || head->next == nullptr) return head;
        ListNode* curr = head;
        while(curr != nullptr && curr->next != nullptr){
            if(curr->val == curr->next->val){
                curr->next = curr->next->next;
            }else{
                curr = curr->next;
            }            
        }
        return head;
    }
};
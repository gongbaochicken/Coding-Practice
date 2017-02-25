// Remove Linked List Elements
// Remove all elements from a linked list of integers that have value val.

// Example
// Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6<br>
// Return: 1 --> 2 --> 3 --> 4 --> 5

// Leetcode: https://leetcode.com/problems/remove-linked-list-elements/


//Solution：
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
     ListNode* removeElements(ListNode* head, int val) {
         if(head == nullptr) return nullptr;
         ListNode* dummy = new ListNode(-1);
         dummy->next = head;
         ListNode* back = dummy;
         while(head){
             if(head->val != val){
                 head = head->next;
                 back = back->next;
             }else{
                 ListNode* temp = head;
                 head = head->next;
                 back->next = back->next->next;
                 delete temp;
             }
         }
         return dummy->next;
     }
 };

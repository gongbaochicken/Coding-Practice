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
        while(head != NULL && head->val == val) {
            head = head->next;
        }
        if (!head) { return NULL; }
        ListNode * curr = head;
        while(curr->next){
            if(curr->next->val == val){
                curr->next = curr->next->next;
            }else{
                curr = curr->next;
            }
        }
        return head;
    }
};

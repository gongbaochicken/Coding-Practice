/*Leetcode: Reverse a singly linked list */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

 /*Recursion
Origin: A->B->C->D->E, head:A next: B->C->D->E
Then you don't need to care about other things, because you know 
that the recursively return ListNode* rest must be: E->D->C->B, then 
the only thing you need to do is to link {rest}->A, which is E->D->C->B->A
*/
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode* next = head->next;
        ListNode* head->next = NULL;
        ListNode* rest = reverseList(next);
        ListNode* tailTemp = rest;
        while(tailTemp->next != NULL){
            tailTemp = tailTemp->next;
        }
        tailTemp->next = head;
        return rest;
    }
};
/*However, this is too slow, costing 119ms...
I made a little change to make it faster!!! I don't go through the 
whole list anymore, when I want to find the end of the "rest".
I handle this before recusion. Now, the cost is only 9 ms.
*/
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode* next = head->next;
        ListNode* head->next = NULL;
        ListNode* rest = reverseList(next);
        ListNode* tailTemp = rest;

        next->next = head;
        return rest;
    }
};

//Iteration: by using dummy node, swap them one by one
class Solution {
public:
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
        return dummy->next;
    }
};



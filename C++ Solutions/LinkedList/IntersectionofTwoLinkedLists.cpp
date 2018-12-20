//Intersection of Two Linked Lists
/*
Write a program to find the node at which the intersection of two singly linked lists begins.

For example, the following two linked lists:

A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗            
B:     b1 → b2 → b3

begin to intersect at node c1.

Notes:

    If the two linked lists have no intersection at all, return null.
    The linked lists must retain their original structure after the function returns.
    You may assume there are no cycles anywhere in the entire linked structure.
    Your code should preferably run in O(n) time and use only O(1) memory.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//Solution in C++:
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == NULL || headB == NULL) return NULL;
        ListNode *pA = headA;
        ListNode *pB = headB;
        int lenA=1, lenB=1;
        while(pA->next) {pA=pA->next;lenA++;}
        while(pB->next) {pB=pB->next;lenB++;}
        pA=headA;pB=headB;
        if(lenA>lenB){
            while(lenA>lenB){
                lenA--;
                pA=pA->next;
            }
        }
        else{
            while(lenA<lenB){
                lenB--;
                pB=pB->next;
            }  
        }
        while(pA!=NULL) {
            if(pA==pB) return pA;
            pA=pA->next;
            pB=pB->next;
        }
        return NULL;
    }
};
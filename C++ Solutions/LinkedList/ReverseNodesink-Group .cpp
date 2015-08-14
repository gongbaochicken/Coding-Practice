//Reverse Nodes in k-Group 
//Tags: Linked List
/*
Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.
You may not alter the values in the nodes, only nodes itself may be changed.
Only constant memory is allowed.

For example, given this linked list: 1->2->3->4->5
For k = 2, you should return: 2->1->4->3->5
For k = 3, you should return: 3->2->1->4->5 
*/

//Solution in C++:
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        int count = 0 ;
        ListNode* p = head;
        while(p){// to see if k elements are left
            count++;
            p = p->next;
            // after end of loop head1 points to (k+1)th node
            if(count == k) break ; 
        }
        // if less than k nodes, it needs no reversion, return head 
        if(count < k) return head;  
        ListNode* q = head, * prev = NULL;
        // reverse the first k nodes
        while(q){                                       
           ListNode * temp1 = q->next;
           q->next = prev;
           if(temp1 == p) break;// the loop goes on till k nodes
           prev = q; //after end of loop head2 points to (k)th node
           q = temp1;
        }
        // from (k+1)th node it is the same problem 
        head->next = reverseKGroup(p , k); 
        return q;            
    }
};
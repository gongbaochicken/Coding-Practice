//Merge k Sorted Lists


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//Use Min Heap
//Time: O(NlogK)
//Space: O(K)
class Solution {
public:
    struct comparison {
        bool operator() (ListNode* p, ListNode* q) const {
            return p->val > q->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, comparison> minHeap;
        for(ListNode* node: lists){
            //nullptr is not allowed to push into minHeap, since there is no val of nullptr
            if(node != nullptr){
                minHeap.push(node);
            }
        }
        ListNode* dummy = new ListNode(-1);
        ListNode* p = dummy;
        while(!minHeap.empty()){
            p->next = minHeap.top();
            minHeap.pop();
            p = p->next;
            if(p->next) minHeap.push(p->next);
        }
        return dummy->next;
    }
};

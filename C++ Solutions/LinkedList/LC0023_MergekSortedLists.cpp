// 23. Merge k Sorted Lists
/*
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

Example:
Input:
[
  1->4->5,
  1->3->4,
  2->6
]
Output: 1->1->2->3->4->4->5->6
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
    struct compare {
        bool operator()(const ListNode* n1, const ListNode* n2) {
            return n1->val > n2->val;
        }        
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) return nullptr;
        priority_queue<ListNode*, vector<ListNode*>, compare> q;
        for (int i = 0; i < lists.size(); ++i) {
            ListNode* node = lists[i];
            if (node != nullptr) q.push(node);
        }
        ListNode* dummy = new ListNode(-1);
        ListNode* p = dummy;
        while(!q.empty()) {
            ListNode* curr = q.top();
            q.pop();
            p->next = new ListNode(curr->val);
            p = p->next;
            if (curr->next) {
                q.push(curr->next);
            }
        }
        return dummy->next;
    }
};
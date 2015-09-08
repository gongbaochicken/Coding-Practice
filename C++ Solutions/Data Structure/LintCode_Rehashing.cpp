//Rehashing
/*
The size of the hash table is not determinate at the very beginning. If the total size of keys is too 
large (e.g. size >= capacity / 10), we should double the size of the hash table and rehash every keys. 
Say you have a hash table looks like below:

size=3, capacity=4

[null, 21, 14, null]
       ↓    ↓
       9   null
       ↓
      null
The hash function is:

int hashcode(int key, int capacity) {
    return key % capacity;
}

here we have three numbers, 9, 14 and 21, where 21 and 9 share the same position as they all have the same 
hashcode 1 (21 % 4 = 9 % 4 = 1). We store them in the hash table by linked list.

rehashing this hash table, double the capacity, you will get:

size=3, capacity=8

index:   0    1    2    3     4    5    6   7
hash : [null, 9, null, null, null, 21, 14, null]
Given the original hash table, return the new hash table after rehashing .
*/


/**
 * Definition of ListNode
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param hashTable: A list of The first node of linked list
     * @return: A list of The first node of linked list which have twice size
     */    
    vector<ListNode*> rehashing(vector<ListNode*> hashTable) {
        // write your code here
        int newSize = 2 * hashTable.size();
        std::vector<ListNode*> newTable(newSize, NULL);
        for(int i = 0; i < hashTable.size(); ++i){
            ListNode* curr = hashTable[i];
            while(curr != NULL){
                ListNode* temp = curr;
                curr = curr->next;
                int val = (temp->val % newSize + newSize) % newSize;
                if(newTable[val] == NULL){
                    newTable[val] = temp;
                    temp->next = NULL;
                }else{
                    ListNode* p = newTable[val];
                    while(p->next != NULL) p = p->next;
                    p->next = temp;
                    temp->next = NULL;
                }
            }
        }
        return newTable;
    }
};
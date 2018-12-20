/*
Design and implement a data structure for Least Recently Used (LRU) cache. 
It should support the following operations: get and put.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, 
otherwise return -1.
put(key, value) - Set or insert the value if the key is not already present. When the cache 
reached its capacity, it should invalidate the least recently used item before inserting a new item.

Follow up:
Could you do both operations in O(1) time complexity?

Example:
LRUCache cache = new LRUCache(2);
cache.put(1, 1);
cache.put(2, 2);
cache.get(1);       // returns 1
cache.put(3, 3);    // evicts key 2
cache.get(2);       // returns -1 (not found)
cache.put(4, 4);    // evicts key 1
cache.get(1);       // returns -1 (not found)
cache.get(3);       // returns 3
cache.get(4);       // returns 4
*/

class LRUCache {
public:
    LRUCache(int capacity) {
      mSize = capacity;
    }

    int get(int key) {
      auto found = hashMap.find(key);
      if (found == hashMap.end()) {
        return -1;
      } else {
        mList.splice(mList.begin(), mList, found->second);
        return found->second->second;
      }
    }

    void put(int key, int value) {
      auto found = hashMap.find(key);
      if(found != hashMap.end()){
        mList.splice(mList.begin(), mList, found->second);
        found->second->second = value;
        return;
      }
      if(hashMap.size() == mSize){
        int keyToDel = mList.back().first;
        mList.pop_back();
        hashMap.erase(keyToDel);
      }
      mList.push_front(make_pair(key, value));
      //mList.emplace_front(key, value);
      hashMap[key] = mList.begin();
    }

private:
    int mSize;
    // DoublelyLinkedList* linkedList;
    list<pair<int, int>> mList;
    map<int, list<pair<int, int>>::iterator> hashMap; //For O(1) look up
};

class LRUCache{
    // https://oj.leetcode.com/problems/lru-cache/
    //
    // Design and implement a data structure for Least Recently Used (LRU) cache. It should support:
    //  * get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1
    //  * set(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, 
    //    it should invalidate the least recently used item before inserting a new item.
    //
public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    int get(int key) {
        if (data.count(key) == 0) {
            return -1;
        }
        moveToFront(key);
        return data[key];
    }
    void set(int key, int value) {
        if (data.count(key) == 0) {
            if (data.size() == cap) {
                eraseBack();
            }
            insertToFront(key);
        }
        else {
            moveToFront(key);
        }
        data[key] = value;
    }
private:
    int cap;
    unordered_map<int, int> data; // map key to value
    list<int> keys; // key's relative position.
        // We choose list<> over other containers because:
        //   a) it supports insert/deletion at random location
        //   b) after insert/deletion, the existing iterator remain valid. This allows us to
        //      store iterators inside another container (map<int, iterator> positions).
        //      other containers (vector/deque) does not have this important feature
    unordered_map<int, list<int>::iterator> positions; // map key to its relative positions
    
    void insertToFront(int key) { // assume: the key is not in cache
        keys.push_front(key);
        positions[key] = keys.begin();
    }
    void moveToFront(int key) { // assume: the key is in cache
        keys.erase(positions[key]);
        insertToFront(key);
    }
    void eraseBack() {
        int lastkey = keys.back();
        positions.erase(lastkey);
        data.erase(lastkey);
        keys.pop_back();
    }
};

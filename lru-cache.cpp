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

/* Add another approach where we maintain the linked list ourselves */

class LRUCache {
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
		return data[key].value;
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
		data[key].value = value;
	}
private:
	struct Node {
		int prev;
		int next;
		int value;
		Node(int p, int n) : prev(p), next(n) {}
		Node() : Node(0, 0) {}
	};
	unordered_map<int, Node> data;
	int front;
	int cap;
	void insertToFront(int key) { // assume: the key is not in cache
		if (data.size() == 0) {
			// create first node
			Node node(key, key);
			data[key] = node;
			front = key;
		}
		else {
			// fix linkage at front
			int next = front;
			int prev = data[front].prev;
			data[next].prev = key;
			data[prev].next = key;
			front = key;
			// create new front node
			Node node(prev, next);
			data[key] = node;
		}
	}
	void moveToFront(int key) { // assume: the key is in cache
		if (key != front) {
			// unlink from current position
			int next = data[key].next;
			int prev = data[key].prev;
			data[next].prev = prev;
			data[prev].next = next;
			// fix linkage at front
			next = front;
			prev = data[front].prev;
			data[next].prev = key;
			data[prev].next = key;
			front = key;
			// update front node
			data[front].next = next;
			data[front].prev = prev;
		}
	}
	void eraseBack() {
		int back = data[front].prev;
		int backback = data[back].prev;
		data[backback].next = front;
		data[front].prev = backback;
		data.erase(back);
	}
public:
	void test() {
		LRUCache cache(2);
		cache.set(1, 10);
		cache.set(2, 20);
		cache.set(3, 30);
		cout << cache.get(1) << endl;
		cout << cache.get(2) << endl;
	}
};

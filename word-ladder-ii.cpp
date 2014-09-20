class Solution {
public:
	vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
		// https://oj.leetcode.com/problems/word-ladder-ii/
		//
		// Given two words (start and end), and a dictionary, find all shortest transformation 
		// sequence(s) from start to end, such that: 
		//   1. Only one letter can be changed at a time
		//   2. Each intermediate word must exist in the dictionary
		// Note:
		//   *  All words have the same length.
		//   *  All words contain only lowercase alphabetic characters.
		// For example:
		//   start = "hit", end = "cog", dict = ["hot","dot","dog","lot","log"]
		// Return [ ["hit","hot","dot","dog","cog"], ["hit","hot","lot","log","cog"] ]
		//

		// Solution: start from the 'end' word. try to change every letter and if the result 
		// is in dict, push it into queue. iterate until we reach the 'start' word. and then
		// use the 'prev' pointer to back trace from start to end
		//
		struct Node {
			string s;
			size_t prev;
			Node(string a, size_t b) : s(a), prev(b) {};
		};
		MyQueue<Node> q;
		Node endNode(end, -1);
		q.push(endNode);
		dict.erase(end);
		vector<vector<string>> result;
		bool done = false;
		while (!done && !q.empty()) { // loop the queue
			unordered_set<string> round2;
			int size = (int)q.size();
			for (int i = 0; i < size; i++) {
				Node node = q.front();
				size_t front = q.frontIndex();
				q.pop();
				for (int j = 0; j < (int)start.length(); j++) { // loop every letter
					char save = node.s[j];
					for (char c = 'a'; c <= 'z'; c++) {
						if (c == save) { continue; }
						node.s[j] = c;
						if (node.s == start) { // found a solution
							done = true;
							vector<string> path;
							path.push_back(start);
							int cur = front;
							do {
								path.push_back(q[cur].s);
								cur = q[cur].prev;
							} while (cur != -1);
							result.push_back(path);
						}
						if (dict.count(node.s) != 0) {
							Node newNode(node.s, front);
							q.push(newNode);
							round2.insert(node.s);
						}
					}
					node.s[j] = save;
				}
			}
			for (string s : round2) { // remove all known words from dict
				dict.erase(s);
			}
		}
		return result;
	}
	template<typename T>
	class MyQueue {
		// specialized queue that remembers all pushed-in items
		vector<T> q;
		size_t index;
	public:
		MyQueue() : index(0) {}
		bool empty() {
			return index == q.size();
		}
		size_t size() {
			return q.size() - index;
		}
		void push(T& t) {
			q.push_back(t);
		}
		T& front() {
			return q[index];
		}
		void pop() {
			index++;
		}
		// specailized operators
		size_t frontIndex() {
			return index;
		}
		T& operator[](size_t index) {
			return q[index];
		}
	};
	void test() {
		string start = "hit";
		string end = "cog";
		vector<string> words = { "hot", "dot", "dog", "lot", "log" };
		unordered_set<string> dict;
		for (string s : words) {
			dict.insert(s);
		}
		vector<vector<string>> result = findLadders(start, end, dict);
		for (auto v : result) {
			for (auto s : v) {
				cout << ' ' << s;
			}
			cout << endl;
		}
	}
};

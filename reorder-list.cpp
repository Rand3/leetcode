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
	void reorderList(ListNode *head) {
		// https://oj.leetcode.com/problems/reorder-list/
		//
		// Given a singly linked list L: L0 -> L1 -> .. Ln-1 -> Ln,
		// reorder it to: L0 -> Ln -> L1 -> Ln-1 -> L2 -> Ln-2 -> ...
		// You must do this in-place without altering the nodes' values.
		// For example,
		// Given {1,2,3,4}, reorder it to {1,4,2,3}.

		// Solution: 3 steps. Step 1, find the middle point
		// 1 2 3 4 5, for odd number, we get the middle point
		//     a   b
		// 1 2 3 4,   for even number, we get 0.5-point away from the center
		//     a   b
		ListNode *fast = head;
		ListNode *slow = head;
		while (fast != NULL && fast->next != NULL) {
			fast = fast->next->next;
			slow = slow->next;
		}
		// Step 2, reverse the second half list
		ListNode *middle = slow;
		ListNode *prev = NULL;
		for (ListNode *p = middle; p != NULL;) {
			ListNode *next = p->next;
			p->next = prev;
			prev = p;
			p = next;
		}
		ListNode *rhead = prev;
		// Step 3, merge the two lists
		for (ListNode *p = head; p != middle;) {
			ListNode *next = p->next;
			p->next = rhead;
			rhead = rhead->next;
			if (rhead == NULL) { break; } // even number list
			p->next->next = next;
			p = next;
		}
	}
	void test() {
		vector<string> tests = { "12345", "1234" };
		for (string s : tests) {
			ListNode *root = Helper::createList(s);
			Helper::out(root);
			reorderList(root);
			Helper::out(root);
		}
	}
};
class Helper {
public:
	static ListNode *createList(string s) {
		int size = (int)s.length();
		ListNode *prev = NULL;
		for (int i = size - 1; i >= 0; i--) {
			int n = s[i] - '0';
			ListNode *node = new ListNode(n);
			node->next = prev;
			prev = node;
		}
		return prev;
	}
	static void out(ListNode *root) {
		while (root != NULL) {
			cout << ' ' << root->val;
			root = root->next;
		}
		cout << endl;
	}
};

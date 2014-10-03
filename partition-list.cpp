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
	ListNode *partition(ListNode *head, int x) {
		// https://oj.leetcode.com/problems/partition-list/
		//
		// Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
		// You should preserve the original relative order of the nodes in each of the two partitions.
		// For example, Given 1->4->3->2->5->2 and x = 3, Return 1->2->2->4->3->5. 

		ListNode smaller(-1);
		smaller.next = head;
		ListNode bigger(-2);
		ListNode *p = &smaller;
		ListNode *q = &bigger;
		while (p->next != NULL) {
			if (p->next->val < x) {
				p = p->next;
			}
			else {
				q->next = p->next;
				q = q->next;
				p->next = q->next;
			}
		}
		q->next = NULL;
		p->next = bigger.next;
		return smaller.next;
	}
	void test() {
		vector<int> v = { 1, 4, 3, 2, 5, 2 };
		ListNode *head = NULL;
		for (int i = v.size() - 1; i >= 0; i--) {
			ListNode *node = new ListNode(v[i]);
			node->next = head;
			head = node;
		}
		out(head);
		head = partition(head, 3);
		out(head);
	}
	void out(ListNode *head) {
		while (head != NULL) {
			cout << head->val << ' ';
			head = head->next;
		}
		cout << endl;
	}
};

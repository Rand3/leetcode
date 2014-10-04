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
	ListNode *rotateRight(ListNode *head, int k) {
		// https://oj.leetcode.com/problems/rotate-list/
		//
		// Given a list, rotate the list to the right by k places, where k is non-negative.
		// For example: Given 1->2->3->4->5->NULL and k = 2, return 4->5->1->2->3->NULL.

		if (head == NULL) { return NULL; }
		ListNode *p = head;
		p = forward(head, p, k);
		ListNode *q = head;
		while (p->next != NULL) {
			p = p->next;
			q = q->next;
			if (q == NULL) { q = head; }
		}
		p->next = head;
		head = q->next;
		q->next = NULL;
		return head;
	}
	ListNode *forward(ListNode *head, ListNode *p, int k) {
		for (int i = 0; i < k; i++) {
			p = p->next;
			if (p == NULL) { p = head; }
		}
		return p;
	}
};

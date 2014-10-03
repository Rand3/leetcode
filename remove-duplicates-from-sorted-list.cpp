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
	ListNode *deleteDuplicates(ListNode *head) {
		// https://oj.leetcode.com/problems/remove-duplicates-from-sorted-list/
		//
		// Given a sorted linked list, delete all duplicates such that each element appear only once.
		// For example,
		// Given 1->1->2, return 1->2.
		// Given 1->1->2->3->3, return 1->2->3.

		if (head == NULL) { return NULL; }
		int dup = head->val;
		for (ListNode *p = head; p->next != NULL;) {
			if (p->next->val == dup) {
				p->next = p->next->next;
			}
			else {
				dup = p->next->val;
				p = p->next;
			}
		}
		return head;
	}
};

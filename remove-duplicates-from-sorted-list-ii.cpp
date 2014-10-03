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
		// https://oj.leetcode.com/problems/remove-duplicates-from-sorted-list-ii/
		//
		// Given a sorted linked list, delete all nodes that have duplicate numbers, 
		// leaving only distinct numbers from the original list.
		// For example,
		// Given 1->2->3->3->4->4->5, return 1->2->5.
		// Given 1->1->1->2->3, return 2->3.

		if (head == NULL) { return NULL; }
		ListNode dummy(-1);
		dummy.next = head;
		for (ListNode *p = &dummy; p->next != NULL && p->next->next != NULL;) {
			ListNode *q = p->next->next;
			if (p->next->val == q->val) {
				while (q->next != NULL && q->next->val == q->val) {
					q = q->next;
				}
				p->next = q->next;
			}
			else {
				p = p->next;
			}
		}
		return dummy.next;
	}
};

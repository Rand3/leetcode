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
	ListNode *mergeTwoLists(ListNode *p, ListNode *q) {
		// https://oj.leetcode.com/problems/merge-two-sorted-lists/
		//
		// Merge two sorted linked lists and return it as a new list. The new list 
		// should be made by splicing together the nodes of the first two lists.

		ListNode dummy(-1);
		ListNode *head = &dummy;
		while (p != NULL && q != NULL) {
			if (p->val < q->val) {
				head->next = p;
				head = head->next;
				p = p->next;
			}
			else {
				head->next = q;
				head = head->next;
				q = q->next;
			}
		}
		head->next = (p != NULL ? p : q);
		return dummy.next;
	}
};

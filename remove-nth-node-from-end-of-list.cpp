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
	ListNode *removeNthFromEnd(ListNode *head, int n) {
		// https://oj.leetcode.com/problems/remove-nth-node-from-end-of-list/
		//
		// Given a linked list, remove the nth node from the end of list and return its head.
		// For example, Given linked list: 1->2->3->4->5, and n = 2. Return 1->2->3->5.
		// Note: Given n will always be valid.

		ListNode dummy(-1);
		dummy.next = head;
		ListNode *fast = &dummy;
		ListNode *slow = fast;
		for (int i = 0; i < n; i++) {
			fast = fast->next;
		}
		while (fast->next != NULL) {
			fast = fast->next;
			slow = slow->next;
		}
		slow->next = slow->next->next;
		return dummy.next;
	}
	void test() {
		ListNode node(1);
		ListNode *result = removeNthFromEnd(&node, 1);
	}
};

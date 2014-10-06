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
	ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
		// https://oj.leetcode.com/problems/add-two-numbers/
		//
		// You are given two linked lists representing two non-negative numbers. 
		// The digits are stored in reverse order and each of their nodes contain 
		// a single digit. Add the two numbers and return it as a linked list.
		// Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
		// Output: 7 -> 0 -> 8

		ListNode dummy(0);
		ListNode *p = &dummy;
		int carry = 0;
		while (l1 != NULL || l2 != NULL || carry != 0) {
			int n1 = 0;
			int n2 = 0;
			if (l1 != NULL) {
				n1 = l1->val;
				l1 = l1->next;
			}
			if (l2 != NULL) {
				n2 = l2->val;
				l2 = l2->next;
			}
			int n = n1 + n2 + carry;
			if (n >= 10) {
				n -= 10;
				carry = 1;
			}
			else {
				carry = 0;
			}
			p->next = new ListNode(n);
			p = p->next;
		}
		return dummy.next;
	}
};

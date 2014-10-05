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
	ListNode *swapPairs(ListNode *head) {
		// https://oj.leetcode.com/problems/swap-nodes-in-pairs/
		//
		// Given a linked list, swap every two adjacent nodes and return its head. 
		// For example,  Given 1->2->3->4, you should return the list as 2->1->4->3. 
		// Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed. 

		ListNode dummy(-1);
		dummy.next = head;
		ListNode *p = &dummy;
		while (p->next != NULL && p->next->next != NULL) {
			// [p] -> [one] -> [two] -> [next]
			// [p] -> [two] -> [one] -> [next]
			ListNode *one = p->next;
			ListNode *two = one->next;
			ListNode *next = two->next;
			p->next = two;
			two->next = one;
			one->next = next;
			p = one;
		}
		return dummy.next;
	}
};

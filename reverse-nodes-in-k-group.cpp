class Solution {
public:
	ListNode *reverseKGroup(ListNode *head, int k) {
		// https://oj.leetcode.com/problems/reverse-nodes-in-k-group/
		//
		// Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
		// If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.
		// You may not alter the values in the nodes, only nodes itself may be changed. Only constant memory is allowed.
		// For example,  Given this linked list : 1->2->3->4->5
		//   For k = 2, you should return : 2->1->4->3->5
		//   For k = 3, you should return : 3->2->1->4->5
		//
		if (k <= 1) { return head; }
		ListNode dummy(0);
		dummy.next = head;
		head = &dummy;
		while (head != NULL) {
			ListNode *last = head;
			for (int i = 0; i < k && last != NULL; i++) {
				last = last->next;
			}
			if (last == NULL) { // last group has less than k nodes, leave them as is
				break;
			}
			ListNode *begin = head->next;
			ListNode *end = last->next;
			//
			// head: node before the group;
			// last: last node in the group
			// end:  node after the group
			//
			//  [head] [n1] [n2] ... [nk] [end]
			//         begin         last
			//
			//  [....] [nk] ... [n2] [n1] [end]
			//         last          head
			//
			ListNode *prev = end;
			ListNode *p = begin;
			while (p != end) {
				ListNode *next = p->next;
				p->next = prev;
				prev = p;
				p = next;
			}
			head->next = last;
			head = begin;
		}
		return dummy.next;
	}
	void test() {
		ListNode a5(5);
		ListNode a4(4); a4.next = &a5;
		ListNode a3(3); a3.next = &a4;
		ListNode a2(2); a2.next = &a3;
		ListNode a1(1); a1.next = &a2;
		ListNode *p = reverseKGroup(&a1, 2);
	}
};

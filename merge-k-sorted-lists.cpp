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
	ListNode *mergeKLists(vector<ListNode*> &lists) {
		// https://oj.leetcode.com/problems/merge-k-sorted-lists/
		//
		// Merge k sorted linked lists and return it as one sorted list. 
		// Analyze and describe its complexity. 

		int size = (int)lists.size();
		ListNode dummy(-1);
		ListNode *p = &dummy;
		// priority_queue: its first element is always the greatest of the elements it contains,
		// using the "less" operator. Now that NodeCompare uses "bigger" operator, we get the
		// smallest element at the front of the queue
		priority_queue<ListNode*, vector<ListNode*>, NodeCompare> q;
		for (ListNode *head : lists) {
			if (head != NULL) {
				q.push(head);
			}
		}
		while (!q.empty()) {
			ListNode *head = q.top();
			q.pop();
			p->next = head;
			p = head;
			ListNode *next = head->next;
			if (next != NULL) {
				q.push(next);
			}
		}
		return dummy.next;
	}
	struct NodeCompare {
		bool operator()(ListNode* a, ListNode* b) {
			return a->val > b->val;
		}
	};
};

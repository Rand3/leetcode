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
    ListNode *insertionSortList(ListNode *head) {
        // https://oj.leetcode.com/problems/insertion-sort-list/
        //
        // Sort a linked list using insertion sort.
        ListNode dummy(0);
        while (head != NULL) {
            ListNode *next = head->next;
            insertNode(&dummy, head);
            head = next;
        }
        return dummy.next;
    }
    ListNode *insertNode(ListNode *head, ListNode *node) {
        while (head->next != NULL && node->val > head->next->val) {
            head = head->next;
        }
        node->next = head->next;
        head->next = node;
    }
};

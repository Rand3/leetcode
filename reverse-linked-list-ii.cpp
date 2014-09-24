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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        // https://oj.leetcode.com/problems/reverse-linked-list-ii/
        //
        // Reverse a linked list from position m to n. Do it in-place and in one-pass. 
        // 1 <= m <= n <= list.size()
        // For example, Given 1-2-3-4-5, m = 2 and n = 4
        // Return 1-4-3-2-5
        ListNode dummy(0);
        dummy.next = head;
        ListNode *p = &dummy;
        for (int i = 1; i < m; i++) {
            p = p->next;
        }
        ListNode *tail = NULL;
        ListNode *tailtail = p->next;
        for (int i = 0; i <= n - m; i++) {
            //  [prev]->[q]->[next]->[nn]
            //  [prev]->[next]->[nn], tail->[q]->nul
            //  [prev]->[nn], tail->[next]->[q]->nul
            //  [prev]->[next]->[q]->[nn]
            ListNode *q = p->next;
            p->next = q->next;
            q->next = tail;
            tail = q;
        }
        tailtail->next = p->next;
        p->next = tail;
        return dummy.next;
    }
    void test() {
        ListNode a1(1), a2(2), a3(3), a4(4), a5(5);
        a1.next = &a2;
        a2.next = &a3;
        a3.next = &a4;
        a4.next = &a5;
        ListNode *result = reverseBetween(&a1, 2, 4);
    }
};

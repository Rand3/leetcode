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
    ListNode *sortList(ListNode *head) {
        // https://oj.leetcode.com/problems/sort-list/
        //
        // Sort a linked list in O(n log n) time and O(1) space complexity.

        // Solution: merge sort
        ListNode dummy(-1);
        dummy.next = head;
        for (int blockSize = 1;; blockSize *= 2) {
            ListNode *prev = &dummy;
            int count = 0;
            while (prev != NULL) {
                prev = merge(prev, blockSize);
                count++;
            }
            if (count == 1) { break; }
        }
        return dummy.next;
    }
    ListNode *merge(ListNode *prev, int blockSize) {
        // [prev]->[start1..end1,start2..end2]->[next block]
        // param prev: the node before the block. i.e. prev->next == begin1
        // param block size: the half size of each 'block' that together forms the list.
        //       the block can be partially filled in. If exist, the first half and
        //       second half block themselve are already sorted
        // return: [prev] to next block. NULL otherwise
        ListNode *start1 = prev->next;
        ListNode *end1 = forward(start1, blockSize - 1);
        ListNode *start2 = forward(end1, 1);
        ListNode *end2 = forward(start2, blockSize - 1);
        // no need to merge unless: first half is full, and second half is not empty
        if (start2 == NULL) { return NULL; }
        while (true) {
            if (start1->val < start2->val) {
                prev->next = start1;
                prev = start1;
                if (prev == end1) {
                    prev->next = start2;
                    prev = end2;
                    break;
                }
                start1 = start1->next;
            }
            else {
                prev->next = start2;
                prev = start2;
                // exit condition: reach end2 when second half is full, 
                // or reach last node when not full.
                if (prev == end2 || prev->next == NULL) {
                    ListNode *end2next = (end2 == NULL ? NULL : end2->next);
                    prev->next = start1;
                    prev = end1;
                    prev->next = end2next;
                    break;
                }
                start2 = start2->next;
            }
        }
        return prev;
    }
    ListNode *forward(ListNode *p, int step) {
        for (int i = 0; i < step && p != NULL; i++) {
            p = p->next;
        }
        return p;
    }
    void test() {
        vector<string> v = { "14623", "14627", "1462350", "1452360" };
        for (string s : v) {
            ListNode *head = createListNode(s);
            out(head);
            ListNode dummy(-1);
            dummy.next = head;
            ListNode *result = merge(&dummy, 6);
            out(dummy.next);
            out(result);
        }
        for (string s : v) {
            ListNode *head = createListNode(s);
            out(head);
            ListNode *result = sortList(head);
            out(result);
        }
    }
    ListNode *createListNode(string s) {
        int size = (int)s.length();
        ListNode *prev = NULL;
        for (int i = size - 1; i >= 0; i--) {
            int n = s[i] - '0';
            ListNode *node = new ListNode(n);
            node->next = prev;
            prev = node;
        }
        return prev;
    }
    void out(ListNode *p) {
        while (p != NULL) {
            cout << ' ' << p->val;
            p = p->next;
        }
        cout << endl;
    }
};

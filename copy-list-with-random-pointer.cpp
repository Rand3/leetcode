/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        // https://oj.leetcode.com/problems/copy-list-with-random-pointer/
        //
        // A linked list is given such that each node contains an additional 
        // random pointer which could point to any node in the list or null.
        // Return a deep copy of the list.
        //
        // Solution: use map to save the relation between the original and the copy one.
        // Or better yet, just put the copy right next to the original one.
        if (head == NULL) { return NULL; }
        RandomListNode *p = head;
        RandomListNode *q;
        while (p != NULL) { // copy every node and insert to original list
            q = new RandomListNode(p->label);
            q->next = p->next;
            p->next = q;
            p = q->next;
        }
        p = head;
        while (p != NULL) { // fix up 'random' pointer
            q = p->next;
            if (p->random != NULL) {
                q->random = p->random->next;
            }
            p = q->next;
        }
        p = head;
        head = p->next;
        while (true) { // split the merged list to to two parts
            // [p] -> [q] -> next(null?)
            q = p->next;
            p->next = q->next;
            p = q->next;
            if (p == NULL) {
                break;
            }
            q->next = p->next;
        }
        return head;
    }
    void test() {
        RandomListNode *head = new RandomListNode(-1);
        RandomListNode *node = new RandomListNode(1);
        head->next = node;
        head->random = node;
        node->random = node;
        RandomListNode *result = copyRandomList(head);
    }
};

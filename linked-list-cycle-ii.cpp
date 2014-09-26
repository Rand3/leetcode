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
    ListNode *detectCycle(ListNode *head) {
        // https://oj.leetcode.com/problems/linked-list-cycle-ii/
        //
        // Given a linked list, return the node where the cycle begins. 
        // If there is no cycle, return null.

        // if head is already on the cycle, no way to figure out where the
        // cycle begins. so we just assume head is not on the cycle.
        //
        // head --> start --> start, where it takes m steps to move from head
        // to start, and then n steps to move a cycle.
        // for example, [1 2 3 4 5 6 3], m = 2 [123], and n = 4 [34563].
        
        ListNode *fast = head;
        ListNode *slow = head;
        
        // 1) now assume n > m
        // - after m steps, slow is at cycle start point, fast is at cycle start + m point, or -(n-m)
        // - after n-m steps, slow is at n-m, fast is at -(n-m) + 2(n-m) = n-m. Meet (1st);
        //   the position is also -(n - (n-m)) = -m
        // - now restart a new slow pointer from head position (-m).
        // - after m steps, when two slow pointers meet, it is where cycle begins
        while (fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) {
                ListNode *slow2 = head;
                while (slow != slow2) {
                    slow = slow->next;
                    slow2 = slow2->next;
                }
                return slow;
            }
        }
        return NULL;
        
        // 2) now assume n <= m, and m % n = k
        // - after m steps, slow is at cycle start point, fast is at cycle start + m % n point = k,
        //   or - (n - k)
        // - after (n-k) steps, slow is at n-k, fast is also at n-k, Meet for the first time;
        //   the position is also -(n - (n-k)) = -k
        // - restart another slow pointer from head (-m)
        // - after m steps, the original slow pointer moves to -k + (m % n) = 0, so they meet the same
    }
};

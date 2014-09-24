/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        // https://oj.leetcode.com/problems/convert-sorted-list-to-binary-search-tree/
        //
        // Given a singly linked list where elements are sorted in ascending order, 
        // convert it to a height balanced BST.
        //
        // http://leetcode.com/2010/11/convert-sorted-list-to-balanced-binary.html
        
        int size = getSize(head);
        return createBST(head, 0, size);
    }
    int getSize(ListNode *head) {
        int n = 0;
        while (head != NULL) {
            head = head->next;
            n++;
        }
        return n;
    }
    TreeNode* createBST(/*_Inout_*/ListNode *&head, int begin, int end) {
        // Input: head of the list node; begin/end denotes the range to be added.
        //     the range includes 'begin' but not 'end' node
        // Output: 'head' is updated to point to 'next' node after the range,
        //     i.e. pointing to 'end' node which is not used during creation.
        //     of course it also returns the root node for subtree just created
        //
        if (begin >= end) {
            return NULL;
        }
        // n = 5, [0..5), middle = 2: [0..2), 2, [3..5)
        // n = 6, [0..6], middle = 3: [0..3), 3, [4..6)
        int middle = begin + (end - begin) / 2;
        TreeNode *left = createBST(head, begin, middle);
        TreeNode *node = new TreeNode(head->val);
        head = head->next;
        TreeNode *right = createBST(head, middle+1, end);
        node->left = left;
        node->right = right;
        return node;
    }
};

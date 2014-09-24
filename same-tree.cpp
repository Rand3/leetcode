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
    bool isSameTree(TreeNode *p, TreeNode *q) {
        // https://oj.leetcode.com/problems/same-tree/
        //
        // Given two binary trees, check if they are equal or not. 
        // Two binary trees are considered equal if they are structurally 
        // identical and the nodes have the same value. 

        if (p == NULL && q == NULL) {
            return true;
        }
        if (p == NULL || q == NULL) {
            return false;
        }
        return (p->val == q->val &&
            isSameTree(p->left, q->left) &&
            isSameTree(p->right, q->right));
    }
};

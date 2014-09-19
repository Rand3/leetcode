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
    bool isBalanced(TreeNode *root) {
        // https://oj.leetcode.com/problems/balanced-binary-tree/
        //
        // Given a binary tree, determine if it is height-balanced. that is,
        // the depth of the two subtrees of every node never differ by more than 1.
        //
        int height;
        return isBalanced(root, height);
    }
    bool isBalanced(TreeNode *root, /* _Out_ */ int &height) {
        if (root == NULL) {
            height = 0;
            return true;
        }
        int left, right;
        if (isBalanced(root->left, left)
            && isBalanced(root->right, right)
            && abs(left - right) <= 1) {
            //
            height = max(left, right) + 1;
            return true;
        }
        return false;
    }
};

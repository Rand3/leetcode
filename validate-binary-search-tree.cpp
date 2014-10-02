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
    bool isValidBST(TreeNode *root) {
        // https://oj.leetcode.com/problems/validate-binary-search-tree/
        //
        // Given a binary tree, determine if it is a valid binary search tree (BST).
        //  * The left subtree of a node contains only nodes with keys less than the node's key.
        //  * The right subtree of a node contains only nodes with keys greater than the node's key.
        //  * Both the left and right subtrees must also be binary search trees.
        
        // in-order traversal
        int prev = INT_MIN;
        stack<TreeNode*> s;
        while (root != NULL || !s.empty()) {
            if (root != NULL) {
                s.push(root);
                root = root->left;
            }
            else {
                root = s.top();
                s.pop();
                if (root != NULL) {
                    if (root->val <= prev) {
                        return false;
                    }
                    prev = root->val;
                    root = root->right;
                }
            }
        }
        return true;
    }
};

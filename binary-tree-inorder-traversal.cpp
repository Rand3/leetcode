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
    vector<int> inorderTraversal(TreeNode *root) {
        // https://oj.leetcode.com/problems/binary-tree-inorder-traversal/
        //
        // Given a binary tree, return the inorder traversal of its nodes' values.
        // For example:  Given binary tree {1,#,2,3}, return [1,3,2]. 
        // Note: Recursive solution is trivial, could you do it iteratively?

        vector<int> result;
        stack<TreeNode*> s;
        while (root != NULL || !s.empty()) {
            if (root != NULL) {
                s.push(root);
                root = root->left;
            }
            else {
                root = s.top();
                s.pop();
                result.push_back(root->val);
                root = root->right;
            }
        }
        return result;
    }
};

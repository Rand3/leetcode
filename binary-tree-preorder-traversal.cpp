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
    vector<int> preorderTraversal(TreeNode *root) {
        // https://oj.leetcode.com/problems/binary-tree-preorder-traversal/
        //
        // Given a binary tree, return the preorder traversal of its nodes' values.
        // Note: Recursive solution is trivial, could you do it iteratively?
        vector<int> result;
        stack<TreeNode*> s;
        s.push(root);
        while (!s.empty()) {
            root = s.top();
            s.pop();
            if (root != NULL) {
                result.push_back(root->val);
                s.push(root->right);
                s.push(root->left);
            }
        }
        return result;
    }
};

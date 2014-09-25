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
    vector<int> postorderTraversal(TreeNode *root) {
        // https://oj.leetcode.com/problems/binary-tree-postorder-traversal/
        //
        // Given a binary tree, return the postorder traversal of its nodes' values.
        // Do it iteratively.
        vector<int> result;
        stack<TreeNode*> s;
        s.push(root);
        while (!s.empty()) {
            TreeNode *peek = s.top();
            if (peek == NULL) {
                s.pop();
                continue;
            }
            if ((peek->left == NULL && peek->right == NULL)
                || peek->left == root || peek->right == root) {
                s.pop();
                result.push_back(peek->val);
                root = peek;
            }
            else {
                s.push(peek->right);
                s.push(peek->left);
            }
        }
        return result;
    }
};

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
    void flatten(TreeNode *root) {
        // https://oj.leetcode.com/problems/flatten-binary-tree-to-linked-list/
        //
        // Given a binary tree, flatten it to a linked list in-place. 
        // For example, Given { 1, 2, 5, 3, 4, #, 6 }.
        // The result should be { 1, #, 2, #, 3, #, 4, #, 5, # 6 }
        //
        TreeNode dummy(0);
        TreeNode *prev = &dummy;
        stack<TreeNode*> s;
        s.push(root);
        while (!s.empty()) {
            root = s.top();
            s.pop();
            if (root == NULL) {
                continue;
            }
            prev->left = NULL;
            prev->right = root;
            prev = root;
            s.push(root->right);
            s.push(root->left);
        }
    }
};

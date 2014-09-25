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
    int minDepth(TreeNode *root) {
        // https://oj.leetcode.com/problems/minimum-depth-of-binary-tree/
        //
        // Given a binary tree, find its minimum depth, which is defined as
        // the number of nodes along the shortest path from the root node 
        // down to the nearest leaf node.
        if (root == NULL) { return 0; }
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        while (!q.empty()) {
            level++;
            int size = (int)q.size();
            for (int i = 0; i < size; i++) {
                root = q.front();
                q.pop();
                if (root->left == NULL && root->right == NULL) {
                    return level;
                }
                if (root->left != NULL) { q.push(root->left); }
                if (root->right != NULL) { q.push(root->right); }
            }
        }
        return level; // should never be here
    }
};

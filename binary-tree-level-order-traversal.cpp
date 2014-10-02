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
    vector<vector<int>> levelOrder(TreeNode *root) {
        // https://oj.leetcode.com/problems/binary-tree-level-order-traversal/
        //
        // Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).
        // For example: Given binary tree {3,9,20,#,#,15,7}, Return
        // [ [3], [9,20], [15,7] ]
        
        vector<vector<int>> result;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            vector<int> row;
            int size = (int)q.size();
            for (int i = 0; i < size; i++) {
                TreeNode *p = q.front();
                q.pop();
                if (p == NULL) { continue; }
                row.push_back(p->val);
                q.push(p->left);
                q.push(p->right);
            }
            if (row.size() != 0) {
                result.push_back(row);
            }
        }
        return result;
    }
};

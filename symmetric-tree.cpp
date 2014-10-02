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
    bool isSymmetric(TreeNode *root) {
        // https://oj.leetcode.com/problems/symmetric-tree/
        //
        // Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
        // Bonus points if you could solve it both recursively and iteratively. 
        if (root == NULL) { return true; }
        // return recursively(root->left, root->right);
        return iteratively(root);
    }
    bool recursively(TreeNode *left, TreeNode *right) {
        if (left == NULL && right == NULL) { return true; }
        if (left == NULL || right == NULL) { return false; }
        return (left->val == right->val
            && recursively(left->left, right->right)
            && recursively(left->right, right->left));
    }
    bool iteratively(TreeNode *root) {
        queue<TreeNode*> q1, q2;
        q1.push(root);
        q2.push(root);
        while (!q1.empty() && !q2.empty()) {
            TreeNode *p1 = q1.front();
            TreeNode *p2 = q2.front();
            q1.pop();
            q2.pop();
            if (p1 == NULL && p2 == NULL) { continue; }
            if (p1 == NULL || p2 == NULL) { return false; }
            if (p1->val != p2->val) { return false; }
            q1.push(p1->left);
            q1.push(p1->right);
            q2.push(p2->right);
            q2.push(p2->left);
        }
        return (q1.empty() && q2.empty());
    }
};

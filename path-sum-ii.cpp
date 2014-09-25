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
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        // https://oj.leetcode.com/problems/path-sum-ii/
        //
        // Given a binary tree and a sum, find all root-to-leaf paths 
        // where each path's sum equals the given sum.
        // For example: Given the below binary tree and sum = 22,
        // .     5
        // .    / \
        // .   4   8
        // .  /   / \
        // .  11 13  4
        // . /  \   / \
        // . 7  2   5 1
        // Return [ [5,4,11,2], [5,8,4,5] ] 

        vector<vector<int>> result;
        if (root == NULL) { return result; }
        vector<int> path;
        helper(root, sum, path, result);
        return result;
    }
    void helper(TreeNode *root, int sum, vector<int> &path, vector<vector<int>> &result) {
        path.push_back(root->val);
        sum -= root->val;
        if (root->left == NULL && root->right == NULL) {
            if (sum == 0) {
                result.push_back(path);
            }
        }
        else {
            if (root->left != NULL) {
                helper(root->left, sum, path, result);
            }
            if (root->right != NULL) {
                helper(root->right, sum, path, result);
            }
        }
        path.pop_back();
    }
};

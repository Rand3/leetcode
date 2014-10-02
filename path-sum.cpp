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
	bool hasPathSum(TreeNode *root, int sum) {
		// https://oj.leetcode.com/problems/path-sum/
		//
		// Given a binary tree and a sum, determine if the tree has a root-to-leaf path 
		// such that adding up all the values along the path equals the given sum. 
		// For example: Given the below binary tree and sum = 22,
		// .     5
		// .    / \
		// .   4   8
		// .  /   / \
		// .  11 13  4
		// . /  \   / \
		// . 7  2   5 1
		// return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.

		if (root == NULL) { return false; } // TODO: sum = 0
		sum -= root->val;
		if (root->left != NULL && hasPathSum(root->left, sum)) {
			return true;
		}
		if (root->right != NULL && hasPathSum(root->right, sum)) {
			return true;
		}
		return (root->left == NULL && root->right == NULL && sum == 0);
	}
};

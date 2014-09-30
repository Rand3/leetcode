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
	int maxPathSum(TreeNode *root) {
		// https://oj.leetcode.com/problems/binary-tree-maximum-path-sum/
		//
		// Given a binary tree, find the maximum path sum. 
		// The path may start and end at any node in the tree. 
		// For example:  Given the below binary tree, 
		// .       1
		// .      / \
		// .     2   3
		// Return 6. 
		int maxAtRoot;
		return helper(root, maxAtRoot);
	}
	int helper(TreeNode *root, int &maxAtRoot) {
		int val = root->val;
		int invalid = min(-1, val - 1); // the node cannot not be part of maxPath, neither by add (-1) nor standalone (val-1)
		int lAtRoot = invalid;
		int rAtRoot = invalid;
		int left = (root->left != NULL ? helper(root->left, lAtRoot) : invalid);
		int right = (root->right != NULL ? helper(root->right, rAtRoot) : invalid);
		maxAtRoot = max(max(val, val + lAtRoot), val + rAtRoot);
		return max(max(max(maxAtRoot, left), right), val + lAtRoot + rAtRoot);
	}
	void test() {
		TreeNode *root = Help::serialize("5,4,8,11,#,13,4,7,2,#,#,#,1");
		Help::out(root);
		int path = maxPathSum(root);
		cout << path << endl;
	}
};

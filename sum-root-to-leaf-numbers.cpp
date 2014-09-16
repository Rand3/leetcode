class Solution {
public:
	int sumNumbers(TreeNode *root) {
		// https://oj.leetcode.com/problems/sum-root-to-leaf-numbers/
		//
		// Given a binary tree containing digits from 0-9 only, each root-to-leaf path 
		// could represent a number. An example is the root-to-leaf path 1->2->3 which 
		// represents the number 123. Find the total sum of all root-to-leaf numbers. 
		// For example, 1.left=2, 1.right=3, return sum = 12 + 13 = 25
		//
		int result = 0;
		if (root != NULL) {
			result = dfs(root, 0);
		}
		return result;
	}
	int dfs(TreeNode *root, int value) {
		// assume: root != NULL
		value += root->val;
		if (root->left == NULL && root->right == NULL) {
			return value;
		}
		int v = 0;
		if (root->left != NULL) {
			v = dfs(root->left, value * 10);
		}
		if (root->right != NULL) {
			v += dfs(root->right, value * 10);
		}
		return v;
	}
	void test() {
		TreeNode *root = Help::serialize("1,2,3,4");
		int result = sumNumbers(root);
		cout << result << endl;
	}
};

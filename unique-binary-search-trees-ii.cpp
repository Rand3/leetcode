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
	vector<TreeNode*> generateTrees(int n) {
		// https://oj.leetcode.com/problems/unique-binary-search-trees-ii/
		//
		// Given n, generate all structurally unique BST's (binary search trees) that store values 1...n.
		// For example, Given n = 3, your program should return all 5 unique BST's shown below. 
		//   1         3     3      2      1
		//    \       /     /      / \      \
		//     3     2     1      1   3      2
		//    /     /       \                 \
		//   2     1         2                 3

		// Solution: DP
		// f(k) := numTrees(k)
		// f(k) = sum (f(i) * f(j)), where i + j + 1 = k, 0 <= i < k
		vector<vector<TreeNode*>> f(n + 1);
		f[0].push_back(NULL);
		if (n == 0) { return f[0]; }
		TreeNode *one = new TreeNode(1);
		f[1].push_back(one);
		for (int k = 2; k <= n; k++) {
			for (int i = 0; i < k; i++) {
				vector<TreeNode*> &lefts = f[i];
				vector<TreeNode*> &rights = f[k - i - 1];
				for (TreeNode *left : lefts) {
					for (TreeNode *right : rights) {
						TreeNode *node = new TreeNode(i + 1);
						node->left = copy(left, 0);
						node->right = copy(right, i + 1);
						f[k].push_back(node);
					}
				}
			}
		}
		return f[n];
	}
	TreeNode *copy(TreeNode *root, int delta) {
		if (root == NULL) { return NULL; }
		TreeNode *node = new TreeNode(root->val + delta);
		node->left = copy(root->left, delta);
		node->right = copy(root->right, delta);
		return node;
	}
	void test() {
		vector<TreeNode*> v = generateTrees(3);
		for (TreeNode *root : v) {
			out(root);
			cout << "==========" << endl;
		}
	}
	void out(TreeNode *root, int indent = 1) {
		if (root != NULL) {
			out(root->right, indent + 1);
			cout << setw(indent * 3) << ' ' << root->val << endl;
			out(root->left, indent + 1);
		}
	}
};

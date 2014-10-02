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
	vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
		// https://oj.leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
		//
		// Given a binary tree, return the zigzag level order traversal of its nodes' values. 
		// (ie, from left to right, then right to left for the next level and alternate between).
		// For example: Given binary tree {3,9,20,#,#,15,7}, Return
		// [ [3], [20,9], [15,7] ]

		// test case:
		//   1
		//  2 3   => [ 1, 32, 45 ]
		// 4   5
		vector<vector<int>> result;
		queue<TreeNode*> q;
		q.push(root);
		bool normal = true;
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
			if (!normal) {
				reverse(row.begin(), row.end());
			}
			if (row.size() != 0) {
				result.push_back(row);
			}
			normal = !normal;
		}
		return result;
	}
};

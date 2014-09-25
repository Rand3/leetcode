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
	vector<vector<int>> levelOrderBottom(TreeNode *root) {
		// https://oj.leetcode.com/problems/binary-tree-level-order-traversal-ii/
		//
		// Given a binary tree, return the bottom-up level order traversal of its nodes' values. 
		// (ie, from left to right, level by level from leaf to root).
		// For example: Given binary tree {3,9,20,#,#,15,7},
		// return: [ [15,7], [9,20], [3] ]

		vector<vector<int>> result;
		if (root == NULL) { return result; }
		queue<TreeNode*> q;
		q.push(root);
		while (!q.empty()) {
			int size = (int)q.size();
			vector<int> row;
			for (int i = 0; i < size; i++) {
				TreeNode *p = q.front();
				q.pop();
				row.push_back(p->val);
				if (p->left != NULL) { q.push(p->left); }
				if (p->right != NULL) { q.push(p->right); }
			}
			result.push_back(row);
		}
		reverse(result.begin(), result.end());
		return result;
	}
	void test() {
		TreeNode *root = Help::decodeTree("3,9,20,#,#,15,7");
		vector<vector<int>> result = levelOrderBottom(root);
		for (auto v : result) {
			for (auto i : v) {
				cout << ' ' << i;
			}
			cout << endl;
		}
	}
};

class Help {
public:
	static TreeNode* decodeTree(string s) {
		// 12##3 =>
		//   1
		//  / \
		// 2  nil
		//  \
		//   3
		int size = s.length();
		if (size == 0) { return NULL; };
		TreeNode *nodes = new TreeNode[size];
		nodes[0].val = s[0] - '0';
		bool left = true;
		TreeNode* parent = &nodes[0];
		TreeNode* cur = &nodes[1];
		for (int i = 1; i < size; i++){
			char c = s[i];
			if (c == ',' || c == ' ') {
				continue;
			}
			if (c != '#') {
				bool neg = false;
				if (c == '-') {
					neg = true;
					i++;
					c = s[i];
				}
				int val = 0;
				while (true) {
					int digit = (c - '0');
					val = val * 10 + digit;
					if (i + 1 < size && s[i + 1] >= '0' && s[i + 1] <= '9')  {
						i++;
						c = s[i];
					}
					else {
						break;
					}
				}
				if (neg) {
					val = -val;
				}
				if (left) {
					parent->left = cur;
				}
				else {
					parent->right = cur;
				}
				cur->val = val;
				cur++;
			}
			if (!left) {
				parent++;
			}
			left = !left;
		}
		return &nodes[0];
	}
};

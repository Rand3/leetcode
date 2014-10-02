/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
	void connect(TreeLinkNode *root) {
		// https://oj.leetcode.com/problems/populating-next-right-pointers-in-each-node/
		//
		// Populate each next pointer to point to its next right node. If there is no next 
		// right node, the next pointer should be set to NULL. Initially, all next pointers 
		// are set to NULL.
		// For example, after calling your function, the following tree becomes:
		// .   1              1->null
		// .  / \     ==>    / \
		// . 2   3          2-> 3->null

		// bfs
		queue<TreeLinkNode*> q;
		q.push(root);
		while (!q.empty()) {
			int size = (int)q.size();
			TreeLinkNode *prev = NULL;
			for (int i = 0; i < size; i++) {
				TreeLinkNode *p = q.front();
				q.pop();
				if (p == NULL) { continue; }
				if (prev != NULL) {
					prev->next = p;
				}
				prev = p;
				q.push(p->left);
				q.push(p->right);
			}
		}
	}
	void test() {
		TreeLinkNode x1(1), x2(2), x3(3);
		x1.left = &x2;
		x1.right = &x3;
		connect(&x1);
	}
};

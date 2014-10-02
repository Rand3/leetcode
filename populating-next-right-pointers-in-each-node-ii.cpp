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
		// https://oj.leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/
		//
		// Follow up for problem at https://oj.leetcode.com/problems/populating-next-right-pointers-in-each-node/.
		// Populate each next pointer to point to its next right node. If there is no next 
		// right node, the next pointer should be set to NULL. Initially, all next pointers 
		// are set to NULL. You may only use constant extra space.
		// The given tree could be any binary tree.
		// For example, after calling your function, the following tree becomes:
		// .    1             1->null
		// .   / \     ==>   /  \
		// .  2   3         2 -> 3->null
		// . / \   \       / \    \
		// . 4 5   7      4-> 5->  7->nul

		// Read: O(1) space means no recursive, no queue, no stack
		if (root == NULL) { return; }
		TreeLinkNode *row = root;
		while (true) {
			TreeLinkNode *prev = NULL;
			for (TreeLinkNode *p = row; p != NULL; p = p->next) {
				// take the node "2" above for example
				if (p->left != NULL) {
					if (prev != NULL) {
						prev->next = p->left;
					}
					else {
						row = p->left;
					}
					prev = p->left;
				}
				if (p->right != NULL) {
					if (prev != NULL) {
						prev->next = p->right;
					}
					else {
						row = p->right;
					}
					prev = p->right;
				}
			}
			if (prev == NULL) { break; }
		}
	}
	void test() {
		TreeLinkNode *root = serial("12345#7");
		connect(root);
		out(root);
	}
	TreeLinkNode *serial(string s) {
		TreeLinkNode *parent = NULL;
		queue<TreeLinkNode*> q;
		TreeLinkNode *root = new TreeLinkNode(s[0] - '0');
		q.push(root);
		for (int i = 1; i < (int)s.length(); i += 2) {
			TreeLinkNode *parent = q.front();
			q.pop();
			int c = s[i];
			if (c != '#') {
				parent->left = new TreeLinkNode(c - '0');
				q.push(parent->left);
			}
			c = s[i + 1];
			if (c != '#') {
				parent->right = new TreeLinkNode(c - '0');
				q.push(parent->right);
			}
		}
		return root;
	}
	void out(TreeLinkNode *root, int indent = 1) {
		if (root == NULL) { return; }
		out(root->right, indent + 1);
		cout << setw(indent * 2) << ' ' << root->val;
		if (root->next != NULL) {
			cout << " ==> " << root->next->val;
		}
		cout << endl;
		out(root->left, indent + 1);
	}
};

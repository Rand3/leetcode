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
	void recoverTree(TreeNode *root) {
	    // https://oj.leetcode.com/problems/recover-binary-search-tree/
	    //
	    // Two elements of a binary search tree (BST) are swapped by mistake.
	    // Please recover the tree in O(1) space without chaning its structure.
	    //
	    
	    // Solution: travesal the BST in correct order. The swap is seen as
	    // one or two "drops" during the course.
	    //
	    //   5 (two drops)     4 (one drop)
	    // 1 x 3 4 x 6,    1 2 x x 5 6
	    //         2             3
	    stack<TreeNode*> s;
	    TreeNode minNode(INT_MIN);
	    TreeNode *prev = &minNode;
	    TreeNode *drop1 = NULL;
	    TreeNode *drop2 = NULL;
	    while (root != NULL || !s.empty()) {
	        if (root != NULL) {
	            s.push(root);
	            root = root->left;
	        }
	        else {
	            root = s.top();
	            s.pop();
	            // visit root
	            if (root->val < prev->val) {
	                if (drop1 == NULL) {
	                    drop1 = prev;
	                }
	                drop2 = root;
	            }
	            prev = root;
	            root = root->right;
	        }
	    }
	    swap(drop1->val, drop2->val);
	}
};

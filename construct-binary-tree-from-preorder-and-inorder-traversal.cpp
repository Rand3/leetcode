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
	TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        // https://oj.leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
        //
        // Given preorder and inorder traversal of a tree, construct the binary tree.
        // Note: You may assume that duplicates do not exist in the tree.
        
        // Pre-Order: root [left] [right]
        // In -Order: [left] root [right]
        return help(preorder, 0, inorder, 0, preorder.size());
	}
	TreeNode *help(vector<int> &preorder, int i, vector<int> &inorder, int j, int size) {
	    if (size == 0) { return NULL; }
	    int val = preorder[i];
	    TreeNode *root = new TreeNode(val);
	    int k = j;
	    while (inorder[k] != val) {
	        k++;
	    }
	    int delta = k - j + 1; // size of (left + root)
	    root->left = help(preorder, i + 1, inorder, j, k - j);
	    root->right = help(preorder, i + delta, inorder, j + delta, size - delta);
	    return root;
	}
};

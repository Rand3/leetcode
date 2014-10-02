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
	TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
	    // https://oj.leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
	    //
	    // Given inorder and postorder traversal of a tree, construct the binary tree.
	    // Note: You may assume that duplicates do not exist in the tree. 
	    
		// in-order:   [left] root [right]
		// post-order: [left] [right] root
        return help(inorder, 0, postorder, 0, (int)inorder.size());
	}
	TreeNode *help(vector<int> &inorder, int i, vector<int> &postorder, int j, int size) {
	    if (size == 0) { return NULL; }
	    int val = postorder[j + size - 1];
	    TreeNode *root = new TreeNode(val);
	    int k = i;
	    while (inorder[k] != val) {
	        k++;
	    }
	    root->left = help(inorder, i, postorder, j, k - i);
	    root->right = help(inorder, k + 1, postorder, j + (k - i), size - (k - i + 1));
	    return root;
	}
};

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
	TreeNode *sortedArrayToBST(vector<int> &nums) {
	    // https://oj.leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
	    //
	    // Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
	    return helper(nums, 0, nums.size());
	}
	TreeNode *helper(vector<int> &nums, int begin, int end) {
	    // convert nums[begin..end) to tree. Note that end is not included in the array
	    int size = end - begin;
	    if (size == 0) { return NULL; }
	    if (size == 1) {
	        return new TreeNode(nums[begin]);
	    }
	    int middle = begin + size / 2;
	    TreeNode *root =  new TreeNode(nums[middle]);
	    root->left = helper(nums, begin, middle);
	    root->right = helper(nums, middle+1, end);
	    return root;
	}
};

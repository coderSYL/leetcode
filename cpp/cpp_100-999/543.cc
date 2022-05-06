// C++
// leetcode 543
// https://leetcode-cn.com/problems/diameter-of-binary-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
	int res = 0;
    int diameterOfBinaryTree(TreeNode* root) {
    	depth_of_tree(root);
    	return res;
    }

    int depth_of_tree(TreeNode* root) {
    	if(!root)
    		return 0;
    	int l = depth_of_tree(root->left);
    	int r = depth_of_tree(root->right);
    	res = max(res, l + r);
    	return 1 + max(l, r);
    }
};
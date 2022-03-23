/*
 * C++
 * leetcode897
 * url:https://leetcode-cn.com/problems/increasing-order-search-tree/
 */

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
	TreeNode* res =nullptr;
	TreeNode* pre = nullptr;

	void visit(TreeNode* root){
		if(!res){
			res = root;
			pre = root;
		}else{
			pre->left =nullptr;
			pre->right = root;
			pre = root;
		}
	}

	void midorder(TreeNode* root){
		if(!root)
			return;
		midorder(root->left);
		visit(root);
		midorder(root->right);
	}
    TreeNode* increasingBST(TreeNode* root) {
    	midorder(root);
    	pre->left = nullptr;
    	pre->right = nullptr;
    	return res;
    }
};
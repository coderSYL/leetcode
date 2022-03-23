/*
 * C++
 * leetcode938
 * url:https://leetcode-cn.com/problems/range-sum-of-bst/
 * 
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
	// 用于记录结果
	int total = 0;

	// 递归前序遍历
	void pre(TreeNode* root, int low, int high){
		// 空root返回
		if(!root)
			return;
		// 符合的值加到答案中
		if(root->val >=low  && root->val<=high)
			total+= root->val;
		// 若此节点的值小于等于low，则左子树的所有节点值必小于low，没必要递归
		if(root->val > low)
			pre(root->left, low, high);
		// 若此结点的值大于等于high，则右子树所有结点的值必大于high，没必要递归
		if(root->val < high)
			pre(root->right, low, high);
	}

    int rangeSumBST(TreeNode* root, int low, int high) {
    	// 初始化total
    	total = 0;
    	// 递归
    	pre(root, low, high);
    	return total;
    }
};
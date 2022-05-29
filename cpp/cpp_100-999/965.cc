// C++
// leetcode 965
// https://leetcode.cn/problems/univalued-binary-tree/

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
	bool inside(TreeNode *r, int val) {
		// 空指针不影响正确性
		if(!r)
			return true;
		// 树值非所需值
		if(r->val != val)
			return false;
		// 排查左右子树
		return inside(r->left, val) && inside(r->right, val);
	}

    bool isUnivalTree(TreeNode* root) {
    	return inside(root, root->val);
    }
};
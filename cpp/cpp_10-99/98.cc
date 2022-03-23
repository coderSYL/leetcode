// C++
// leetcode 98
// https://leetcode-cn.com/problems/validate-binary-search-tree/

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
	bool judge(TreeNode* root, long lowerLimit, long upperLimit) {
		if(!root)
			return	true;
		long v = root -> val;
		if(v <= lowerLimit || v >= upperLimit)
			return	false;
		return	judge(root -> left, lowerLimit, v) && judge(root -> right, v, upperLimit);
	}
    bool isValidBST(TreeNode* root) {
    	return	judge(root, LONG_MIN, LONG_MAX);
    }
};

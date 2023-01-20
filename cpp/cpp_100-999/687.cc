// C++
// leetcode 687
// https://leetcode.cn/problems/longest-univalue-path/

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
	// 返回值为，包含结点 p 的单向长度最长长度
	// res 为 global 的可往两个子树延伸的最长长度
	int dfs(TreeNode* p, int &res) {
		// 空结点直接返回 0
		if (p == nullptr)
			return 0;

		// l, r存储左右子树的答案
		int l = dfs(p->left, res), r = dfs(p->right, res);

		// 若左子树与当前结点值相同则 +1，否则归零
		if (p->left && p->left->val == p->val)
			l++;
		else
			l = 0;

		// 右子树同理
		if (p->right && p->right->val == p->val)
			r++;
		else
			r = 0;

		// 结算一次 res
		res = max(res, l + r);
		
		return max(l, r);
	}

    int longestUnivaluePath(TreeNode* root) {
    	int res = 0;
    	dfs(root, res);
    	return res;
    }
};
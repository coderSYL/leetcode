// C++
// leetcode 1161
// https://leetcode.cn/problems/maximum-level-sum-of-a-binary-tree/

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
	int level = 0;
	int sum[10001];

	void dfs(TreeNode* p, int lvl) {
		sum[lvl] += p -> val;
		level = max(lvl, level);
		if (p->left)
			dfs(p -> left, lvl + 1);
		if (p->right)
			dfs(p -> right, lvl + 1);
	}

    int maxLevelSum(TreeNode* root) {
    	memset(sum, 0, sizeof(sum));

    	dfs(root, 1);
    	int res = 1;
    	for(int i = 1; i <= level; i++) {
    		if (sum[i] > sum[res])
    			res = i;
    	}

    	return res;
    }
};
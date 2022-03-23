// C++
// leetcode 95
// https://leetcode-cn.com/problems/unique-binary-search-trees-ii/

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
	vector<TreeNode*> dfs(int l, int r) {
		if(l > r)
			return	{nullptr};
		vector<TreeNode*> res;
		for(int i = l; i <= r; i++) {
			// i 为根结点的值
			auto left = dfs(l, i - 1), right = dfs(i + 1, r);
			for(auto x : left) {
				for(auto y : right) {
					TreeNode *p = new TreeNode(i);
					p -> left = x;
					p -> right = y;
					res.push_back(p);
				}
			}
		}
		return	res;
	}
    vector<TreeNode*> generateTrees(int n) {
    	return	dfs(1, n);
    }
};
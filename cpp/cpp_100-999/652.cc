// C++
// leetcode 652
// https://leetcode.cn/problems/find-duplicate-subtrees/

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
	vector<TreeNode*> res;
	map<string, int> cnt;
	string dfs(TreeNode *root) {
		if (root == nullptr)
			return " ";
		string key = "";
		key += to_string(root -> val) + "_" + dfs(root -> left) + dfs(root -> right);
		cnt[key]++;
		if (cnt[key] == 2)
			res.push_back(root);
		return key;
	}

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
    	dfs(root);
    	return res;
    }
};
// C++
// leetcode 1305
// https://leetcode-cn.com/problems/all-elements-in-two-binary-search-trees/

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
	vector<int> res;
	void mid_order(TreeNode* root) {
		if(root == nullptr)
			return;
		mid_order(root->left);
		res.push_back(root->val);
		mid_order(root->right);
	}

    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
    	mid_order(root1);
    	mid_order(root2);
    	sort(res.begin(), res.end());
    	return res;
    }
};
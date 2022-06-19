// C++
// leetcode 508
// https://leetcode.cn/problems/most-frequent-subtree-sum/

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
	map<int, int> cnt;

	int getTreeSum(TreeNode* root) {
		int res = root->val;
		if(root->left)
			res += getTreeSum(root->left);
		if(root->right)
			res += getTreeSum(root->right);
		cnt[res]++;
		return res;
	}

    vector<int> findFrequentTreeSum(TreeNode* root) {
    	getTreeSum(root);
    	int cur = INT_MIN;
    	vector<int> res;
    	for(auto [k, v] : cnt) {
    		if(v > cur) {
    			cur = v;
    			res.clear();
    			res.push_back(k);
    		} else if(v == cur) {
    			res.push_back(k);
    		}
    	}
    	return res;
    }
};
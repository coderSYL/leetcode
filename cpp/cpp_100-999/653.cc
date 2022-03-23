// C++
// leetcode 653
// https://leetcode-cn.com/problems/two-sum-iv-input-is-a-bst/

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
	int k_;
	TreeNode* root_;
	int minInTree_;
	bool find(TreeNode* root, int a) {
		while(root != nullptr) {
			if(root->val == a)
				return true;
			if(root->val < a)
				root = root->right;
			else
				root = root->left;
		}
		return false;
	}

	bool midOrder(TreeNode* root) {
		if(root == nullptr)
			return false;
		if(midOrder(root->left))
			return true;
		int target = k_ - root->val;
		if(target < minInTree_)
			return false;
		if(target != root->val && find(root_, target))
			return true;
		return midOrder(root->right);
	}

    bool findTarget(TreeNode* root, int k) {
    	k_ = k;
    	root_ = root;
    	TreeNode* p = root;
    	while(p->left != nullptr)
    		p = p->left;
    	minInTree_ = p->val;
    	// cout<<p->val;
    	return midOrder(root);
    }
};


// 方法二：宫水三叶的
// class Solution {
// public:
// 	unordered_set<int> s;
//     bool findTarget(TreeNode* root, int k) {
//     	if(root == nullptr)
//     		return false;
//     	if(s.count(k-root->val) == 1)
//     		return true;
//     	s.insert(root->val);
//     	return findTarget(root->left, k) || findTarget(root->right, k);
//     }
// };
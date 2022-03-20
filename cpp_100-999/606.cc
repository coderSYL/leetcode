// C++
// leetcode 606
// https://leetcode-cn.com/problems/construct-string-from-binary-tree/

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
	void getRes(string &s, TreeNode* root) {
		s += to_string(root->val);
		if(root->left == nullptr) {
			if(root->right == nullptr)
				return;
			else {
				s += "()(";
				getRes(s, root->right);
				s += ")";
				return;
			}
		} else {
			if(root->right == nullptr) {
				// 左边有，右边没有
				s += "(";
				getRes(s, root->left);
				s += ")";
				return;
			} else {
				// 左右都有
				s += "(";
				getRes(s, root->left);
				s += ")(";
				getRes(s, root->right);
				s += ")";
				return;
			}
		}
	}
    string tree2str(TreeNode* root) {
    	string s = "";
    	if(root != nullptr)
    		getRes(s, root);
    	return s;
    }
};
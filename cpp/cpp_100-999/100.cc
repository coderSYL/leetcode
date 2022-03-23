// C++
// leetcode 100
// https://leetcode-cn.com/problems/same-tree/comments/
// 简简单单一个递归

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
    bool isSameTree(TreeNode* p, TreeNode* q) {
    	if(p == nullptr && q == nullptr)
    		return	 true;
    	if(p == nullptr || q == nullptr)
    		return	 false;

    	if(p -> val != q -> val)
    		return	false;
    	return	isSameTree(p -> left, q -> left) && isSameTree(p -> right, q -> right);
    }
};
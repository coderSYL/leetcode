// C++
// leetcode 99
// https://leetcode-cn.com/problems/recover-binary-search-tree/
// 非递归的中序遍历

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
    void recoverTree(TreeNode* root) {
    	stack<TreeNode*> stk;
    	TreeNode *x = nullptr, *y = nullptr, *pre = nullptr, *p = root;
    	while(!stk.empty() || p != nullptr) {
    		while(p != nullptr) {
    			stk.push(p);
    			p = p->left;
    		}
    		p = stk.top();
    		stk.pop();
    		if(pre != nullptr && p->val < pre->val) {
    			y = p;
    			if(!x) {
    				x = pre;
    			} else
    				break;
    		}
    		pre = p;
    		p = p->right;
    	}
    	swap(x->val, y->val);
    }
};
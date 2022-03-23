// C++
// leetcode 114
// https://leetcode-cn.com/problems/flatten-binary-tree-to-linked-list/

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
    void flatten(TreeNode* root) {
    	if(!root) return;
    	stack<TreeNode*> stk;
    	stk.push(root);
    	TreeNode *tmp, *cur = nullptr;
    	
    	while(!stk.empty()) {
    		tmp = stk.top();
    		stk.pop();
    		if(!cur) cur = tmp;
    		else {
    			cur -> left = nullptr;
    			cur -> right = tmp;
    			cur = tmp;
    		}
            if(tmp -> right) stk.push(tmp -> right);
    		if(tmp -> left) stk.push(tmp -> left);
    	}
    	return;
    }
};
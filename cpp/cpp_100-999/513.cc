// C++
// leetcode 513
// https://leetcode.cn/problems/find-bottom-left-tree-value/

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
    int findBottomLeftValue(TreeNode* root) {
    	queue<TreeNode*> q;
    	q.push(root);
    	int level = 0, res = 0;
    	while(!q.empty()) {
    		int size = q.size();
    		res = q.front()->val;
    		while(size--) {
    			auto p = q.front();
    			if(p->left)
    				q.push(p->left);
    			if(p->right)
    				q.push(p->right);
    			q.pop();
    		}
    	}
    	return res;
    }
};